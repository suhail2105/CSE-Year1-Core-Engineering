#include<stdio.h>
#include<math.h>
int main()
{
    int choice;
    printf("choose what would u like to see");
    printf("\n1)addition of any amount of number\n2)sum of digits in a number and its count\n3)reverse and pallindrome\n4)relation of numbers\n5)finding x in a quad equation\n6)checking if a number is an armstrong number\n:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
            int t,i,a,s=0,n;
            printf("\ninput how many numbers would u like to add: ");
            scanf("%d",&a);
            t=a;
            for(i=1;i<=a;i++)
            {
                printf("input your %d number: ",i);
                scanf("%d",&n);
                s+=n;
            }
            printf("the sum of all the numbers = %d",s);
            
        }
        break;
        case 2:
        {
            int c=0,n,t,s=0,a;
            printf("\ninput a number to find its sum: ");
            scanf("%d",&n);
            t=n;
            for(;n!=0;n/=10)
            {
                s=s+(n%10);
                c++;
            }
            printf("\nthe sum of the digits of %d = %d",t,s);
            printf("\nthe amount of digits in %d = %d",t,c);
        }
        break;
        case 3:
        {
            int t,r,s=0,n;
            printf("input a number to reverse and check if its a pallindrome: ");
            scanf("%d",&n);
            t=n;
            for(;n!=0;n/=10)
            {
                r=n%10;
                s=(10*s)+r;
            }
            printf("the reverse of %d = %d",t,s);
            if (t==s)
            printf("\n%d is a pallindrome",t);
            else
            printf("\n%d is not a pallindrome",t);
        }
        break;
        case 4:
        {
            int prev,curr,n,i;
            printf("\nhow many numbers would u like to comapre (atlease 2): ");
            scanf("%d",&n);
            printf("\ninput your 1st number: ");
            scanf("%d",&prev);
            for(i=2;i<=n;i++)
            {
                printf("\ninput your %d number: ",i);
                scanf("%d",&curr);
                if(prev>curr)
                printf("%d is bigger than %d\n",prev,curr);
                else if(curr>prev)
                printf("%d is bigger than %d\n",curr,prev);
                else
                printf("%d and %d are equal\n",prev,curr);
                prev = curr;                
            }
        }
        break;
        case 5:
        {
            int a,b,c;
            float r1,r2,s;
            printf("input the values of a,b,c in ax^2+bx+c=0: ");
            scanf("%d%d%d",&a,&b,&c);
            s = pow(b,2)-(4*a*c);
            r1 = (-b+sqrt(s))/2*a;
            r2 = (-b-sqrt(s))/2*a;
            if(s>0)
            printf("the equation has real and distinct roots = %f\t%f\n",r1,r2);
            else if(s==0)
            printf("the equation has real and equal roots = %f\t%f\n",r1,r2);
            else
            printf("the equation has imaginary roots\n");
        }
        case 6:
        {
            int s=0,r,t,n,p,nd;
            printf("input how many digits does the number have: ");
            scanf("%d",&nd);
            printf("input a number to check if its an armstrong no.: ");
            scanf("%d",&n);
            for(t=n;n!=0;n/=10)
            {
                r=n%10;
                p=1;
                for(int i=0;i<nd;i++)
                {
                    p*=r;
                }
                s+=p;
            }
            if(s==t)
            printf("%d is an armstrong number",t);
            else
            printf("%d is not an armstrong number",t);
        }
        break;
    }
    return 0;
}