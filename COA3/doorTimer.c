void doorTimer()
{//	Register[17]=0;
	while(Register[17]<15)		
	{
		Register[17]++;
	}
	printf("YOUR DOOR IS OPEN FROM 15 Minutes\n Please close the door");
}
