#!/usr/bin/python3.6

def forward(self):
	if self.send("Forward") == 84:
		return 84
	if self.receive() == 84:
		return 84
	return 0

def left(self):
	if self.send("Left") == 84:
		return 84
	if self.receive() == 84:
		return 84
	return 0

def right(self):
	if self.send("Right") == 84:
		return 84
	if self.receive() == 84:
		return 84
	return 0

def look(self):
	if self.send("Look") == 84:
		return 84
	if self.receive() == 84:
		return 84
	self.looked = self.buff_str
	return 0

def inventory(self):
	if self.send("Inventory") == 84:
		return 84
	if self.receive() == 84:
		return 84
	self.ressources[0] = int(self.buff_str.split(",", 1)[0]
			.split("food ", 1)[1])
	return 0

def broadcast(self, message):
	if self.send("Broadcast " + message) == 84:
		return 84
	if self.receive() == 84:
		return 84
	return 0

def get_team_slots(self):
	if self.send("Connect_nbr") == 84:
		return 84
	if self.receive() == 84:
		return 84
	return 0

def fork(self):
	if self.send("Fork") == 84:
		return 84
	if self.receive() == 84:
		return 84
	return 0

def take_item(self, item):
	if self.send("Take " + item) == 84:
		return 84
	if self.receive() == 84:
		return 84
	if self.res is True:
		for i, l_item in enumerate(self.ressources_name):
			if l_item is item:
				self.ressources[i] += 1
				print(self.ressources)
	return 0

def set_item(self, item):
	if self.send("Set " + item) == 84:
		return 84
	if self.receive() == 84:
		return 84
	if self.res is True:
		for i, l_item in enumerate(self.ressources_name):
			if l_item is item:
				self.ressources[i] -= 1
	return 0

def incantation(self):
	if self.send("Incantation") == 84:
		return 84
	if self.receive() == 84:
		return 84
	return 0
