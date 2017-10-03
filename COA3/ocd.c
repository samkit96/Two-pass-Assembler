void doorOpen()
{	doorTimer();
	energyMonitor();
	Register[27]=1;
	printf("Lights On");
}
void doorClose()
{
	Register[27]=0;
	printf("Lights Off");
}
