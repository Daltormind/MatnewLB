// relabel labels nodes adjacent to solid

#include "wet.h"

void wet::relabel()
{
	for(k=k1;k<k2;k++)
	{

	if(mask[k]!=28)
	{
	// One away
	
	if(mask[d[k][0]]==28){mask[k]=1;}else if(mask[d[d[k][0]][0]]==28){mask[k]=2;}
	
	if(mask[d[k][1]]==28){mask[k]=1;}else if(mask[d[d[k][1]][1]]==28){mask[k]=2;}
	
	if(mask[d[k][2]]==28){mask[k]=1;}else if(mask[d[d[k][2]][2]]==28){mask[k]=2;}
	
	if(mask[d[k][3]]==28){mask[k]=1;}else if(mask[d[d[k][3]][3]]==28){mask[k]=2;}
	
	if(mask[d[k][4]]==28){mask[k]=1;}else if(mask[d[d[k][4]][4]]==28){mask[k]=2;}
	
	if(mask[d[k][5]]==28){mask[k]=1;}else if(mask[d[d[k][5]][5]]==28){mask[k]=2;}
	
	if(mask[d[k][6]]==28){mask[k]=1;}else if(mask[d[d[k][6]][6]]==28){mask[k]=2;}
	
	if(mask[d[k][7]]==28){mask[k]=1;}else if(mask[d[d[k][7]][7]]==28){mask[k]=2;}
	
	if(mask[d[k][8]]==28){mask[k]=1;}else if(mask[d[d[k][8]][8]]==28){mask[k]=2;}
	
	if(mask[d[k][9]]==28){mask[k]=1;}else if(mask[d[d[k][9]][9]]==28){mask[k]=2;}
	
	if(mask[d[k][10]]==28){mask[k]=1;}else if(mask[d[d[k][10]][10]]==28){mask[k]=2;}
	
	if(mask[d[k][11]]==28){mask[k]=1;}else if(mask[d[d[k][11]][11]]==28){mask[k]=2;}
	
	if(mask[d[k][12]]==28){mask[k]=1;}else if(mask[d[d[k][12]][12]]==28){mask[k]=2;}
	
	if(mask[d[k][13]]==28){mask[k]=1;}else if(mask[d[d[k][13]][13]]==28){mask[k]=2;}
	
	if(mask[d[k][14]]==28){mask[k]=1;}else if(mask[d[d[k][14]][14]]==28){mask[k]=2;}
	
	if(mask[d[k][15]]==28){mask[k]=1;}else if(mask[d[d[k][15]][15]]==28){mask[k]=2;}
	
	if(mask[d[k][16]]==28){mask[k]=1;}else if(mask[d[d[k][16]][16]]==28){mask[k]=2;}
	
	if(mask[d[k][17]]==28){mask[k]=1;}else if(mask[d[d[k][17]][17]]==28){mask[k]=2;}
	
	
	}
	}
}