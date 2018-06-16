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
        Manager = Manager;
    }

    public bool CallCommand(string command)
    {
        string[] array = command.Split(' ');
        int i = 0;

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
            Manager.MapSizeX = int.Parse(array[1]);
            Manager.MapSizeY = int.Parse(array[2]);
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
        return true;
    }

    private static bool MapContent(string[] array)
    {
        if (array.Length < 10 
            || (array.Length > 10 && (array.Length - 10) % 9 != 0))
            return false;
        return true;
    }

    private static bool TeamName(string[] array)
    {
        if (array.Length < 2)
            return false;
        return true;
    }

    private static bool NewPlayer(string[] array)
    {
        if (array.Length != 7)
            return false;
        return true;
    }

    private static bool PlayerPosition(string[] array)
    {
        if (array.Length != 5)
            return false;
        return true;
    }

    private static bool PlayerLvl(string[] array)
    {
        if (array.Length != 3)
            return false;
        return true;
    }

    private static bool PlayerInventory(string[] array)
    {
        if (array.Length != 11)
            return false;
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
        return true;
    }

    private static bool ResourceCollect(string[] array)
    {
        if (array.Length != 3)
            return false;
        return true;
    }

    private static bool PlayerDeath(string[] array)
    {
        if (array.Length != 2)
            return false;
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
