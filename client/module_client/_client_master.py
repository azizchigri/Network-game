#!/usr/bin/python3.6

def master(self):
	while (1):
		if self.inventory() == 84:
			return 84
		message = self.check_messages("IncantNow")
		if message is not None and self.ressources[0] >= 25:
			sender = message[2]
			self.follow_incant(message, sender)
		i = 0
		check_incant = True
		while i < len(self.ressources_incant[self.level - 1]) and check_incant is True:
			if self.ressources[i + 1] < self.ressources_incant[self.level - 1][i]:
				check_incant = False
			i += 1
		if check_incant is True and self.ressources[0] > 25:
			if self.try_incant() == 84:
				return 84
		if self.get_ressources() == 84:
			return 84

def follow_incant(self, message, sender):
	direction = 0
	while message is None or (not "0" in message[0][8]
			and message[2] in sender
			and "IncantNow" in message[4]
			and self.ressources[0] > 14):
		if "IncantFail" is message[4] or "IncantConfirm" \
				is message[4]:
			return 0
		elif direction == 0:
			direction = int(message[0][8])
			if self.follow[direction]() == 84:
				return 84
		else:
			direction = 0
		message = self.check_messages("Incant")
		if self.look() == 84:
			return 84
		message = self.check_messages("Incant")
	if ("IncantFail" in message[4] or "IncantConfirm" in message[4]) \
			and message[2] in sender:
		return 0
	if (self.wait_incant(message, sender)) == 84:
		return 84
	return 0

def wait_incant(self, message, sender):
	if self.broadcast(":" + self.team + ":" + self.id + ":"
			+ sender + ":IncantOk") == 84:
		return 84
	while ("0" in message[0][8]
			and message[2] in sender
			and "IncantNow" in message[4]):
		if self.look() == 84:
			return 84
		message = self.check_messages("Incant")
	if "IncantFail" is message[4]:
		return 0
	else:
		if self.wait_end_incant(message, "Elevation") == 84:
			return 84
		if self.wait_end_incant(message, "Current level") == 84:
			return 84
		if self.res is True:
			if self.receive() == 84:
				return 84
			if self.receive() == 84:
				return 84
			self.level += 1
	return 0

def wait_end_incant(self, message, waiting):
	while (not waiting in message[4]):
		if self.look() == 84:
			return 84
		if self.looked is "":
			if self.receive() == 84:
				return 84
			if self.receive() == 84:
				return 84
		if "Current level" in self.buff_str:
			return 0
		message_tmp = self.check_messages(waiting)
		if message_tmp is not None:
			message = message_tmp
	return 0

def try_incant(self):
	nb_client = 1
	client_incant = ""
	k = 0 if (self.level == 1 or self.level % 2 == 0) else 1
	while self.ressources[0] > 15 and nb_client < (self.level - k):
		if self.broadcast(":" + self.team + ":" + self.id
				+ ":all:IncantNow:" + str(self.level)) == 84:
			return 84
		if self.inventory() == 84:
			return 84
		message = self.check_messages("IncantOk")
		if message is not None:
			if len(client_incant) != 0:
				client_incant += ","
			client_incant += message[2]
			nb_client += 1
	if nb_client == (self.level - k):
		if self.do_incant(client_incant) == 84:
			return 84
	else:
		if self.broadcast(":" + self.team + self.id + ":all:"
				+ ":IncantFail") == 84:
			return 84
	return 0

def do_incant(self, clients):
	if self.broadcast(":" + self.team + ":" + self.id + ":all"
			+ ":IncantConfirm:" + clients) == 84:
		return 84
	for i, j in enumerate(self.ressources_incant[self.level - 1]):
		while j != 0:
			if self.set_item(self.ressources_name[i + 1]) == 84:
				return 84
			j -=1
	if self.incantation() == 84:
		return 84
	if self.receive() == 84:
		return 84
	if self.res is True:
		self.level += 1
	return 0