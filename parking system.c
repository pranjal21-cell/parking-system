#include <stdio.h>
#include <stdlib.h>

#define TOTAL_SLOTS 10  //number of parking slots

typedef struct {
    int slot_id;
    int is_occupied;
} ParkingSlot;
void initialize_slots(ParkingSlot slots[], int size) {
    for (int i = 0; i < size; i++) {
        slots[i].slot_id = i + 1;
        slots[i].is_occupied = 0; // 0 means empty, 1 means occupied
    }
}

int find_available_slot(ParkingSlot slots[], int size) {
    for (int i = 0; i < size; i++) {
        if (!slots[i].is_occupied) {
            return i;
        }
    }
    return -1; // No available slot
    }
void park_vehicle(ParkingSlot slots[], int size) {
    int slot_index = find_available_slot(slots, size);
    if (slot_index == -1) {
        printf("No available parking slots.\n");
    } else {
        slots[slot_index].is_occupied = 1;
        printf("Vehicle parked at slot %d.\n", slots[slot_index].slot_id);
    }
}
void leave_parking(ParkingSlot slots[], int size, int slot_id) {
    if (slot_id < 1 || slot_id > size || !slots[slot_id - 1].is_occupied) {
        printf("Invalid slot number or slot already empty.\n");
    } else {
        slots[slot_id - 1].is_occupied = 0;
        printf("Slot %d is now free.\n", slot_id);
    }
}

void display_slots(ParkingSlot slots[], int size) {
    printf("Parking Slot Status:\n");
    for (int i = 0; i < size; i++) {
        printf("Slot %d: %s\n", slots[i].slot_id, slots[i].is_occupied ? "Occupied" : "Available");
    }
}
int main() {
    ParkingSlot slots[TOTAL_SLOTS];
    initialize_slots(slots, TOTAL_SLOTS);
    int choice, slot_id;

    while (1) {
        printf("\n1. Park Vehicle\n2. Leave Parking\n3. Display Slots\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
   switch (choice) {
            case 1:
                park_vehicle(slots, TOTAL_SLOTS);
                break;
            case 2:
                printf("Enter slot number to vacate: ");
                scanf("%d", &slot_id);
                leave_parking(slots, TOTAL_SLOTS, slot_id);
                break;
            case 3:
                display_slots(slots, TOTAL_SLOTS);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    
    return 0;
}
