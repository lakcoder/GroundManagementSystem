
 void addground(struct ground groundDB[],int Gsize,char G_name[],char G_city[],struct ground_REC)
{
         int i=0,found=0;
         while(i<Gsize&& found=0)
	  {
		if(((strcmp(groundDB[i].name,G_name)==0)&&((strcmp(groundDB[i].city,G_city)==0))
		{
			found=1;
		}
		else
		i++;
	  }
		if(found==1)
		{
		   ret_value=FAILURE;
                }
                else
                   {
                     groundDB[i]=ground_REC;
                      ret_value=SUCCESS;
                   }
             return ret_value;
}
