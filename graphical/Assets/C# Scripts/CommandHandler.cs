using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CommandHandler : MonoBehaviour {

    public static BoardManager Manager { set; get; }

    private readonly Func<string[], bool>[] FuncPtr = { MapSize, TileContent,
        MapContent, TeamName, NewPlayer, PlayerPosition, PlayerLvl,
        PlayerInventory, Expulsion, Broadcast, IncantationStart,
        IncantationEnd, EggLaying, ResourceDrop, ResourceCollect, PlayerDeath,
        EggLayed, EggHatching, PlayerConnectionEgg, EggDeath, TimeUnit,
        TimeUnitModif, EndGame, Msg, UnknownCommand, UnknownParam};
    private readonly string[] FuncName = { "msz", "bct", "mct", "tna", "pnw", "ppo",
        "plv", "pin", "pex", "pbc", "pic", "pie", "pfk", "pdr", "pgt", "pdi",
        "enw", "eht", "ebo", "edi", "sgt", "sst", "seg", "smg", "suc", "sbp"};

    private void Start()
    {
        Manager = gameObject.AddComponent<BoardManager>();
        Manager.transform.SetParent(transform);
        Manager.name = "BoardManager";
    }

    public bool CallCommand(string command)
    {
        string[] array = command.Split(' ');
        int i = 0;

        if (command.Length != 0)
            Debug.Log("Received : " + command);
        foreach (var func in FuncPtr)
        {
            if (array != null && array[0] == FuncName[i])
            {
                return FuncPtr[i](array);
            }
            i += 1;
        }
        return false;
    }

    private static bool MapSize(string[] array)
    {
        if (array.Length != 3)
            return false;
        try
        {
            Manager.SetMapSizeX(int.Parse(array[1]));
            Manager.SetMapSizeY(int.Parse(array[2]));
            Manager.InitBackground(0, 0, -3);
        } catch (Exception)
        {
            return false;
        }
        return true;
    }

    private static bool TileContent(string[] array)
    {
        if (array.Length != 10)
            return false;
        int x = int.Parse(array[1]);
        int y = int.Parse(array[2]);
        if (x < 0 || y < 0 || x > Manager.MapSizeX || y > Manager.MapSizeY)
            return false;
        for (int i = 3; i < 10; i ++)
        {
            Manager.Map[x, y].resources[i - 3] = int.Parse(array[i]);
        }
        return true;
    }

    private static bool MapContent(string[] array)
    {
        if (array.Length < 10 
            || (array.Length > 10 && (array.Length - 10) % 9 != 0))
            return false;
        for (int i = 1; i < array.Length && array.Length - i >= 9; i += 9)
        {
            int x = int.Parse(array[i]);
            int y = int.Parse(array[i + 1]);
            if (x < 0 || y < 0 || x > Manager.MapSizeX || y > Manager.MapSizeY)
                return false;
            for (int j = i + 3; j < 10; j++)
            {
                Manager.Map[x, y].resources[j - 3] = int.Parse(array[j]);
            }
        }
        return true;
    }

    private static bool TeamName(string[] array)
    {
        if (array.Length < 2)
            return false;
        Manager.TeamName = new List<string>(array);
        Manager.TeamName.RemoveAt(0);
        return true;
    }

    private static bool NewPlayer(string[] array)
    {
        if (array.Length != 7)
            return false;
        Character player = Manager.SpawnCharacter(int.Parse(array[2]), int.Parse(array[3]), int.Parse(array[1]), array[6]);
        player.ChangeOrientation((Character.Orientation)int.Parse(array[4]));
        player.Level = int.Parse(array[5]);
        return true;
    }

    private static bool PlayerPosition(string[] array)
    {
        if (array.Length != 5)
            return false;
        Character player = Manager.Players[int.Parse(array[1])].GetComponent<Character>();
        player.MoveTo(Manager.GetTileCenter(int.Parse(array[2]), int.Parse(array[3])));
        player.ChangeOrientation((Character.Orientation)int.Parse(array[4]));
        return true;
    }

    private static bool PlayerLvl(string[] array)
    {
        if (array.Length != 3)
            return false;
        Character player = Manager.Players[int.Parse(array[1])].GetComponent<Character>();
        player.Level = int.Parse(array[2]);
        return true;
    }

    private static bool PlayerInventory(string[] array)
    {
        if (array.Length != 11)
            return false;
        Character player = Manager.Players[int.Parse(array[1])].GetComponent<Character>();
        player.SetPosition(int.Parse(array[2]), int.Parse(array[3]));
        for (int i = 4; i < 11; i++)
        {
            player.resources[i - 4] = int.Parse(array[i]);
        }
        return true;
    }

    private static bool Expulsion(string[] array)
    {
        if (array.Length != 2)
            return false;
        return true;
    }

    private static bool Broadcast(string[] array)
    {
        if (array.Length != 3)
            return false;
        return true;
    }

    private static bool IncantationStart(string[] array)
    {
        if (array.Length < 5)
            return false;
        return true;
    }

    private static bool IncantationEnd(string[] array)
    {
        if (array.Length != 3)
            return false;
        return true;
    }

    private static bool EggLaying(string[] array)
    {
        if (array.Length != 2)
            return false;
        return true;
    }

    private static bool ResourceDrop(string[] array)
    {
        if (array.Length != 3)
            return false;
        Character player = Manager.Players[int.Parse(array[1])].GetComponent<Character>();
        Manager.Map[player.CurrentX, player.CurrentY].resources[int.Parse(array[2])] += 1;
        player.resources[int.Parse(array[2])] -= 1;
        return true;
    }

    private static bool ResourceCollect(string[] array)
    {
        if (array.Length != 3)
            return false;
        Character player = Manager.Players[int.Parse(array[1])].GetComponent<Character>();
        Manager.Map[player.CurrentX, player.CurrentY].resources[int.Parse(array[2])] -= 1;
        player.resources[int.Parse(array[2])] += 1;
        return true;
    }

    private static bool PlayerDeath(string[] array)
    {
        if (array.Length != 2)
            return false;
        int n = int.Parse(array[1]);
        Character player = Manager.Players[n].GetComponent<Character>();
        Destroy(player.gameObject);
        return true;
    }

    private static bool EggLayed(string[] array)
    {
        if (array.Length != 5)
            return false;
        return true;
    }

    private static bool EggHatching(string[] array)
    {
        if (array.Length != 2)
            return false;
        return true;
    }

    private static bool PlayerConnectionEgg(string[] array)
    {
        if (array.Length != 2)
            return false;
        return true;
    }

    private static bool EggDeath(string[] array)
    {
        if (array.Length != 2)
            return false;
        return true;
    }

    private static bool TimeUnit(string[] array)
    {
        if (array.Length != 2)
            return false;
        return true;
    }

    private static bool TimeUnitModif(string[] array)
    {
        if (array.Length != 2)
            return false;
        return true;
    }

    private static bool EndGame(string[] array)
    {
        if (array.Length != 2)
            return false;
        return true;
    }

    private static bool Msg(string[] array)
    {
        if (array.Length != 2)
            return false;
        return true;
    }

    private static bool UnknownCommand(string[] array)
    {
        if (array.Length != 1)
            return false;
        return true;
    }

    private static bool UnknownParam(string[] array)
    {
        if (array.Length != 1)
            return false;
        return true;
    }
}
