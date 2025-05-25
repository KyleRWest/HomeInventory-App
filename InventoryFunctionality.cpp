#include "InventoryManager.h"
#include <QFile>
#include <QTextStream>

void InventoryManager::addItem(const InventoryItem& itemType) {
	items.append(itemType);
}
void InventoryManager::editItem(int index, const InventoryItem& newType) {
	if (index >= 0 && index < items.size()) {
		items[index] = newType;
	}
}

void InventoryManager::deleteItem(int index) {
	if (index >= 0 && index < items.size()) {
		items.removeAt(index);
	}
}

QList<InventoryItem> InventoryManager::getItems() const {
	return items;
}

QList<InventoryItem> InventoryManager::searchItems(const QString& keyword) const {
	QList<InventoryItem> results;
	for (const InventoryItem& item : items) {
		if (item.itemType.contains(keyword, Qt::CaseInsensitive) ||
			item.category.contains(keyword, Qt::CaseInsensitive)) {
			results.append(item);
		}
	}
	return results;
}

void InventoryManager::loadFromFile(const QString& filepath) {
	QFile file(filepath);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

	items.clear(); // Clear existing items
	QTextStream in(&file);
	while (!in.atEnd()) {
		QString line = in.readLine();
		QStringList parts = line.split(',');
		if (parts.size() == 5) {
			InventoryItem item(parts[0], parts[1], parts[2], parts[3], parts[4].toInt());
			items.append(item);
		}
	} file.close();
}

void InventoryManager::saveToFile(const QString& filepath) const {
	QFile file(filepath);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return;
	QTextStream out(&file);
	for (const InventoryItem& item : items) {
		out << item.itemType << "|" << item.category << "|" << item.description << "|" << item.room << "|" << item.quantity << "\n";
	} file.close();
}

/*#include "InventoryManager.h"
#include <fstream>

void InventoryManager::addItem(const std::string& itemType, const std::string& category, int quantity) {
	items.push_back({ itemType, category, quantity });
}

std::vector<Item> InventoryManager::getItem() const {
	return items;
}

//Create boolean methods for cases
bool InventoryManager::updateItemQuantity(size_t index, int newQuantity) {
	if (index < items.size()) {
		items[index].quantity = newQuantity;
		return true;
	}
	return false;
}

bool InventoryManager::removeItem(size_t index) {
	if (index < items.size()) {
		items.erase(items.begin() + index);
		return true;
	}
	return false;
}

bool InventoryManager::saveToFile(const std::string& filename) const {
	std::ofstream outFile(filename);
	if (!outFile.is_open()) return false;

	//create directory
	for (const auto& item : items) {
		outFile << item.itemType << "," << item.category << "," << item.quantity << "\n";
	}

	outFile.close();
	return true;
}

bool InventoryManager::loadFromFile(const std::string& filename) {
	std::ifstream inFile(filename);
	if (!inFile.is_open()) return false;

	items.clear(); //clear existing inventory

	std::string line;
	while (getline(inFile, line)) {
		size_t pos1 = line.find(',');
		size_t pos2 = line.rfind(',');

		//validate directory
		if (pos1 != std::string::npos && pos2 != std::string::npos && pos1 != pos2) {
			std::string name = line.substr(0, pos1);
			std::string category = line.substr(pos1 + 1, pos2 - pos1 - 1);
			int quantity = std::stoi(line.substr(pos2 + 1));
			items.push_back({ name, category, quantity });
		}
	}

	inFile.close();
	return true;
}

size_t InventoryManager::getItemCount() const {
	return items.size();
}*/

