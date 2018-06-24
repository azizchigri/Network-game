#!/usr/bin/python3.6

def connect(self, args):
	if self.ia_com.client_receive(self.sock_fd, self.buffer) == 84:
		return 84
	if "WELCOME\n" not in self.buffer.value.decode('utf-8'):
		print("Error: Client not connected to a zappy server")
		return 84
	if self.ia_com.client_send(self.sock_fd, args[1]) == 84:
		return 84
	if self.ia_com.client_receive(self.sock_fd, self.buffer):
		return 84
	if "ko\n" in self.buffer.value.decode('utf-8'):
		print("Error: Bad Team Name. Retry to connect with an" \
		+ " allowed team name")
		return self.ia_com.return_error(self.sock_fd)
	return 0

def run(self):
	if self.broadcast(":" + self.team +
			":NewPlayer:0:NewPlayer") == 84:
		return 84
	if self.get_ressources() == 84:
		return 84
	if self.get_ressources() == 84:
		return 84
	message = self.check_messages("NewID")
	print (message)
	if message is not None:
		self.id = message[5]
	else:
		self.id = "0"
	if self.roles(message) == 84:
		return 84
	return 0