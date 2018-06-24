#!/usr/bin/python3.6

import ctypes

class Client():

	from ._client_launch import connect, run
	from ._client_communication import send, receive, check_messages, \
			check_dead, check_buff
	from ._client_commands import forward, left, right, inventory, look, \
			get_team_slots, set_item, take_item, broadcast, fork, \
			incantation
	from ._client_newplayer import get_ressources, go_to_food_place, \
			search_most_food, roles
	from ._client_queen import queen, queen_check_broadcast
	from ._client_master import master, follow_incant, try_incant, \
			do_incant, wait_incant

	def __init__(self, sock_fd, ia_com, args, len):
		self.sock_fd = sock_fd
		self.team = args[1][:len].decode('utf-8')
		self.id = "NewPlayer"
		self.is_alive = True
		self.level = 1
		self.list_client = "0"
		self.ressources = [9, 0, 0, 0, 0, 0, 0]
		self.ressources_name = ["food", "linemate", "deraumere",
				"sibur", "mendiane", "phiras", "thystame"]
		self.ressources_incant = [[1, 0, 0, 0, 0, 0],
				[1, 1, 1, 0, 0, 0], [2, 0, 1, 0, 2, 0],
				[1, 1, 2, 0, 1, 0], [1, 2, 1, 3, 0, 0],
				[1, 2, 3, 0, 1, 0], [2, 2, 2, 2, 2, 1]]
		self.res = True
		self.looked = ""
		self.buffer = (ctypes.c_char * 4096)()
		self.buff_str = ""
		self.memory_message = []
		self.ia_com = ia_com
		self.follow = {1 : self.forward,
				2 : self.forward,
				3 : self.left,
				4 : self.left,
				5 : self.left,
				6 : self.right,
				7 : self.right,
				8 : self.forward,
		}


