// Free and Open Source project made by Fifex (@fifex)
// License: GNU General Public License v3.0 (GPL-3.0)
// Discord: @fif3x_
// Telegram: t.me/fif3x
// Github: https://github.com/fif3x

#ifndef FSMF_HPP
#define FSMF_HPP // Include guard to prevent multiple inclusions of this header file

#include <iostream>
#include <vector>
#include <random> // Include all necessary headers/libraries
#include <cstdint>
#include <map>


class msgSystm {
public:

	uint64_t msgID = 0; // Declare msgID as an unisgned 64-bit integer

	std::vector<uint64_t> msgIDs = {
		// This vector will hold all the message IDs
		// It is initialized empty and will be filled as messages are sent
	};

	std::map<uint64_t, std::string> msgMap = {
		// This map will hold the message ID as the key and the message as the value
		// It is initialized empty and will be filled as messages are sent
	};

	template<typename T>
	void logMsg(T msg, uint64_t msgID) { //this function is to log the message and its ID
		msgMap[msgID] = msg; // Store the message in the map with its ID as the key
		std::cout << "Message logged: " << msg << " ID: " << msgID << std::endl; // say what message was logged and with what ID
	}

	void showMsgIDs() { //function to how all msg IDs
		for (const auto& id : msgIDs) {
			std::cout << id << std::endl;
		}
	}

	void showMsgMap() { //function to show all messages and their IDs
		for (const auto& pair : msgMap) {
			std::cout << pair.first << " : " << pair.second << std::endl;
		}
	}
	

	template<typename T>
	void sendMsg(T msg) { //function to send a msg
		std::random_device rd;
		std::mt19937_64 gen(rd());  // Initialize random number generator with a random seed
		std::uniform_int_distribution<uint64_t> dist(10000000000000000000ULL, 18446744073709551615ULL); // Generate a random 64-bit unsigned integer in the range [10^19, 2^64-1]

		msgID = dist(gen); // Generate a random message ID

		msgIDs.push_back(msgID); // Add the message ID to the vector of message IDs
		logMsg(msg, msgID); // Log the message with its ID

		std::cout << msg << std::endl; // Print the message to the console

	}

	void deleteMsg(uint64_t msgID) { //function to delete a msg

		auto it = std::remove(msgIDs.begin(), msgIDs.end(), msgID);
		msgIDs.erase(it, msgIDs.end()); //remove the message ID from the vector

		auto mapIt = msgMap.find(msgID);
		msgMap.erase(mapIt); //delete the message from the map
	}

	void deleteAllMsgs() { //function to delete all msgs
		msgIDs.clear();
		msgMap.clear();
	}

	template<typename T>
	uint64_t findMsgIDByValue(const T& value) { //helper function
		for (const auto& pair : msgMap) {
			if (pair.second == value) {
				return pair.first;
			}
		}
		throw std::runtime_error("Message not found");
	}



};

#endif
