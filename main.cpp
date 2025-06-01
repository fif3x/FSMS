// Free and Open Source project made by Fifex (@fifex)
// License: GNU General Public License v3.0 (GPL-3.0)
// Discord: @fif3x_
// Telegram: t.me/fif3x
// Github: https://github.com/fif3x




#include <iostream> // Include the necessary headers

#include "messageSystem.hpp" // Include the header file for the message system

int main() {

	msgSystm ms; // Create an instance of the message system

	ms.sendMsg("Hello, World"); // Send a message

	ms.showMsgIDs(); // Show all message IDs
	ms.showMsgMap(); // Show all messages and their IDs

	ms.deleteMsg(ms.findMsgIDByValue("Hello, World")); // Delete a message by its value - could also be done by ID

	ms.showMsgIDs();  // Show all message IDs after deletion
	ms.showMsgMap(); // Show all messages and their IDs after deletion

	ms.sendMsg("Goodbye, World"); // Send another message

	ms.showMsgIDs(); // Show all message IDs after sending another message
	ms.showMsgMap(); // Show all messages and their IDs after sending another message

	ms.deleteAllMsgs(); // Delete all messages

	std::cout << "-" << std::endl;

	ms.showMsgIDs(); // Show all message IDs after deleting all messages
	ms.showMsgMap(); // Show all messages and their IDs after deleting all messages

	std::cout << "-" << std::endl;

	return 0x0; // Exit code 0 (0x0) - could also be "return 0;"
}