/*
 * Created on: Nov 3, 2014
 * Author: hyc
 *
 * Project : We are establishing a program for warehouse owners.
 *           It simply gets main informations about objects and added to the inventory
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct part {
	int partNumber;
	int partType;
};
void Part_create(struct part *part) {
	printf("Enter part number:");
	scanf("%d", &(part->partNumber));
	printf("Enter part type:");
	scanf("%d", &(part->partType));
}
int main(int argc, char *argv[]) {
	int inventory_size = 0; //Size of inventory list
	int max_size = 5;
	int part_counter = 0; // Quantity of elements in inventory
	int i;
	struct part *inventory; // Inventory
	struct part *current_part = inventory; // Point to last member of inventory
	int input;

	// Creating an inventory which has size of max_size
	inventory = (struct part *) malloc(max_size);
	if (inventory == NULL) {
    // Checking if malloc is succeed
		printf("Malloc failed\n");
	} else {
    //We are gathering stock informations untill user press "0"
		printf("Enter 0 to terminate or press other numbers to enter a new part:");
		scanf("%d", &input);
		while (input != 0) {
			if (inventory_size == max_size) {
    //If we esceed our inventory size, we'll double the size with realloc
				max_size = 2 * max_size;
				current_part = inventory + inventory_size; //update the adress of last element for not overwrite on it
				inventory = (struct part *) realloc(inventory, max_size); // Double the size of inventory
				if (inventory == NULL) {
					printf(
							"Realloc ile yeniden bellek ayirma islemi basarisiz\n");
					break;
				}
			}
    //Calling Part_create for taking new info's of inventory cagirarak yeni stok bilgilerini alalim
			Part_create(current_part);
			inventory[part_counter] = *current_part;
			part_counter++;
			inventory_size++;
			current_part++;
			printf(
					"\n\nEnter 0 to terminate, anything else to enter a new part:");
			scanf("%d", &input);
		}
//Print Inventory Size
		printf("Inventory size:%d\n", inventory_size);
//Print Informations of each element
		for (i = 0; i < part_counter; i++) {
			printf("Part Number : %d Part Type : %d \n",
					inventory[i].partNumber, inventory[i].partType);
		}
	}
	return 0;
}
