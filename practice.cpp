#include <stdio.h>
#include <string.h>
//// define a structure for menu items
struct menu_item {
    int id;
    char name[50];
    float price;
};

void order(char ordername[50], float orderprice, float *bill){
	int q = 1;
	float total;
	printf("Enter the quantity of %s: ",ordername);
	scanf("%d",&q);
	if(q<1)q=1;
	total = q*orderprice;
	*bill = *bill+total;
	
}
void printBill(float total_bill){
		printf("\n-------------------------------\n\tTotal Bill\n-------------------------------\n\n");
        printf("$-%f",total_bill );
		printf("\n\n-------------------------------\n");
}

int main(){
	float total_bill = 0;
	printf("\n\n------------Welcome to our cafe--------------\n");
	    // create an array of menu items
    struct menu_item menu[] = {
        {1, "Coffee", 3.50},
        {2, "Tea", 2.50},
        {3, "Sandwich", 5.00},
        {4, "Cake", 4.00},
        {5, "Smoothie", 4.50},
        {6, "Milk Shake", 3.50},
        {7, "Juice", 4.50},
    };

    int menu_size = sizeof(menu) / sizeof(menu[0]); // number of menu items

    // add items to the order
    int choice;
    do {
        printf("\n\tMenu:\n");
        for (int i = 0; i < menu_size; i++) {
            printf("%d. %s - $%.2f\n", menu[i].id, menu[i].name, menu[i].price);
        }
        printf("0. Finish order *\n");
        printf("\n----You can order by entering the option number of the item that you want----\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) break;
        
        if (choice < 0 || choice > menu_size) {
            printf("\n*** Invalid choice ***\n");
            continue;
        }
		order(menu[choice-1].name,menu[choice-1].price, &total_bill);
		printf("Anything else?\n1.yes\n2.no\n");
		int choice2;
		scanf("%d",&choice2);
		
		if(choice2 == 2)break;
		if (choice2 != 1 && choice2 != 2) {
            printf("Invalid choice ***\n");
            break;
        }
    } while (1);
		printBill(total_bill);
}


