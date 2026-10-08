#include<stdio.h>
#include<stdlib.h>
int main()
{
    int item_id[5]={100,101,102,103,104};
    float price[5]={20.00,95.50,15.50,60.00,30.00};
    int stock[5]={10,20,35,76,87};
    int choice,purchase,search=-1;
    do
    {    printf("1)all the items\n2)find items\n3)restock items\n4)remove items\n5)exit\n: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                for (int i=0;i<5;i++)
                {
                    printf("item id = %d\titem price = %.2f\tstock = %d\n",item_id[i],price[i],stock[i]);
                }
            }
            break;
            case 2:
            {
                printf("input the id of the item: ");
                scanf("%d",&purchase);
                int found=0;
                for(int i=0;i<5;i++)
                {
                    if(purchase == item_id[i])
                    {
                        printf("ITEM FOUND\nitem price = %.2f\tstock = %d\n",price[i],stock[i]);
                        found=1;
                        break;
                    }
                }
                if(found==0)
                printf("ITEM NOT FOUND!\n");
            }
            break;
            case 3:
            {
                int restock,found=0,quantity;
                printf("input an item id you would u like to restock: ");
                scanf("%d",&restock);
                for(int i=0;i<5;i++)
                {
                    if(restock==item_id[i])
                    {
                        printf("\ninput quantity to restock: ");
                        scanf("%d",&quantity);
                        stock[i]+=quantity;
                        found = 1;
                        printf("\nthe item has been restocked\nitem id = %d\tafter restock=%d\n",restock,stock[i]);
                        break;
                    }
                }
                if(found==0)
                printf("ITEM ID NOT FOUND\n");
            }
            break;
            case 4:
            {
                int id, found = 0, quantity;
                printf("input the id of item u want to remove: ");
                scanf("%d", &id);
                for (int i = 1; i < 5; i++)
                {
                    if (id == item_id[i])
                    {
                        found = 1;
                        printf("\ninput the quantity to remove: ");
                        scanf("%d", &quantity);
                        int t = stock[i];
                        if (t - quantity < 0)
                        {
                            printf("\ninvalid attempt for id = %d\tstock = %d (cannot remove more than the stock has)\n", id, t);                        
                        }
                        else
                        {
                            stock[i] -= quantity;
                            printf("\nfor item id = %d\tafter quantity removal = %d\n", item_id[i], stock[i]);
                        }
                        break;
                    }
                }
                if (found == 0)
                {
                    printf("ITEM NOT FOUND!\n");
                }
            }
            break;
            case 5:
            {
                printf("thank you");
                exit(0);
            }
            break;
            default:
            printf("INVALID CHOICE!");
        }
    }while(choice!=5);
    return 0;    
}