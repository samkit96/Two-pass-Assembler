void filterStatus()
{

if(reg[6]<2)				//current water in filter
{
printf("your filter level is just 2 litres\n Add water to it");
}
}
 void addWater()
{
while(reg[6]<10)
{
reg[6]++;
}
printf(" container is full");
}
