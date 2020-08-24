#include <stdio.h>
#include <math.h>

int main(void)
{
	FILE * pFile;
   int n;
   char name [100];

   pFile = fopen ("camera_pose_info.txt","w");

	const double inter_degree = 36 ;
	const double inter_radian = inter_degree * (3.141592/180.0) ;
	const double r = 0.06855 ;

	int index = 0 ;
	for( double degree=0 ; degree<360 ; degree+=inter_degree )
	{
		double radian = degree * (3.141592/180.0) ;
		double cos_ = cos(radian) ;
		double sin_ = sin(radian) ;

		float x = r * cos_ ;
		float y = r * sin_ ;
		float yaw = inter_radian*index ;

		fprintf(pFile, "<joint name=\"camera_%02d_joint\" type=\"fixed\">\n", index) ;
		fprintf(pFile, "    <parent link=\"top_link\"/>\n") ;
		fprintf(pFile, "    <child link=\"camera_%02d_pose_link\"/>\n", index) ;
		fprintf(pFile, "    <origin xyz=\"%f %f 0.04930\" rpy=\"1.57 0.5235986666666667 %f\"/>\n", x, y, yaw) ;
		fprintf(pFile, "</joint>\n") ;
		fprintf(pFile, "<link name=\"camera_%02d_pose_link\" />\n", index) ;
		fprintf(pFile, "\n") ;
		
      	index++ ;
	}

	
	fclose (pFile);

	return 0 ;
}
