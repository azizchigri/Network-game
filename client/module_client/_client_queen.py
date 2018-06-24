#!/usr/bin/python3.6

def queen(self, message):
	if message is not None and len(message) == 7 \
			and message[5] == 0:
		self.list_client = message[6]
	while (1):
		if self.get_team_slots() == 84:
			return 84
		if self.fork() == 84:
			return 84
		if self.queen_check_broadcast() == 84:
			return 84

def queen_check_broadcast(self):
	message = self.check_messages("NewPlayer")
	if message is not None:
		if self.inventory() == 84:
			return 84
		if self.ressources[0] == 0:
			if self.broadcast(":" + self.team + ":"
					+ self.id
					+ ":NewPlayer:NewID:0:"
					+ self.list_client):
				return 84
		else:
			new_client = str(int(self.list_client[-1]) + 1)
			self.list_client += "," + new_client
			if self.broadcast(":" + self.team + ":"
					+ self.id
					+ ":NewPlayer:NewID:"
					+ new_client):
				return 84
	return 0