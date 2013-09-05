#include <cstring>
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
//#include <mpi.h>
#include <string>
#include <sstream>


using namespace std;
template<typename V> V mod(V,V);


int main()
{

//Declare variables

int mx=100; //Size in x direction
int my=100; //Size in Y direction
int t; //Timestep
int i,j; //Indexes
double f0[mx+2][my+2],f1[mx+2][my+2],f2[mx+2][my+2],f3[mx+2][my+2],f4[mx+2][my+2],f5[mx+2][my+2],f6[mx+2][my+2],f7[mx+2][my+2],f8[mx+2][my+2];//Distribution function
double rho[mx+2][my+2];
double mu[mx+2][my+2];
double u[mx+2][my+2],v[mx+2][my+2];
double Lap;
double mu0,rho0G=1.0,rho0L=1.0;
double ux[k]=0,uy[k]=0;
double kappa=0.01;
double beta=0.01;
double gradRhoC0,gradRhoC1,gradRhoC2,gradRhoC3,gradRhoC4,gradRhoC5,gradRhoC6,gradRhoC7,gradRhoC8;
double gradMuC0,gradMuC1,gradMuC2,gradMuC3,gradMuC4,gradMuC5,gradMuC6,gradMuC7,gradMuC8;
double gradRhoU0,gradRhoU1,gradRhoU2,gradRhoU3,gradRhoU4,gradRhoU5,gradRhoU6,gradRhoU7,gradRhoU8;
double gradMuU0,gradMuU1,gradMuU2,gradMuU3,gradMuU4,gradMuU5,gradMuU6,gradMuU7,gradMuU8;
double FC0,FC1,FC2,FC3,FC4,FC5,FC6,FC7,FC8;
double FU0,FU1,FU2,FU3,FU4,FU5,FU6,FU7,FU8;
double gradRhoCx,gradRhoCy,gradRhoUx,gradRhoUy;
double gradMuCx,gradMuCy,gradMuUx,gradMuUy;
double FUx,FUy,FCx,FCy;
double FM0,FM1,FM2,FM3,FM4,FM5,FM6,FM7,FM8,FMx,FMy;
double f0zero,f1zero,f2zero,f3zero,f4zero,f5zero,f6zero,f7zero,f8zero;
double f0zeroBar,f1zeroBar,f2zeroBar,f3zeroBar,f4zeroBar,f5zeroBar,f6zeroBar,f7zeroBar,f8zeroBar;
double d1=1;//unknown purpose
int tend=100;
double tau=0.5;
// Initialisation
	for(i=1;i<=mx;i++)
    {
     for(j=1;j<=my;j++)
        {
      rho[i][j]=rho0L;
	  u[i][j]=0.0;
	  v[i][j]=0.0;
	    rho[i][j]=(rho0G+rho0L)/2.0+(rho0L-rho0G)/2.0*tanh(2.0/d1*(sqrt((i-mx/2.0)*2.0+(j-my/2.0)*2.0)-25.0));

        }
    }


// Initialise Variables

for(j=1;j<=my;j++)
    {
        for(i=1;i<=mx;i++)
        {
         ux[k]=u[i][j];
         uy[k]=v[i][j];

         f0[i][j] = 4.0/9.0*rho[i][j]*(1.0-1.5*(ux[k]*ux[k]+uy[k]*uy[k]));
         f1[i][j] = 1.0/9.0*rho[i][j]*(1.0+3.0*ux[k]+3.0*ux[k]*ux[k]-1.5*uy[k]*uy[k]);
         f2[i][j] = 1.0/9.0*rho[i][j]*(1.0+3.0*uy[k]+3.0*uy[k]*uy[k]-1.5*ux[k]*ux[k]);
         f3[i][j] = 1.0/9.0*rho[i][j]*(1.0-3.0*ux[k]+3.0*ux[k]*ux[k]-1.5*uy[k]*uy[k]);
         f4[i][j] = 1.0/9.0*rho[i][j]*(1.0-3.0*uy[k]+3.0*uy[k]*uy[k]-1.5*ux[k]*ux[k]);
         f5[i][j] = 1.0/36.0*rho[i][j]*(1.0+3.0*(ux[k]+uy[k]+ux[k]*ux[k]+uy[k]*uy[k])+9.0*ux[k]*uy[k]);
         f6[i][j] = 1.0/36.0*rho[i][j]*(1.0+3.0*(-ux[k]+uy[k]+ux[k]*ux[k]+uy[k]*uy[k])-9.0*ux[k]*uy[k]);
         f7[i][j] = 1.0/36.0*rho[i][j]*(1.0+3.0*(-ux[k]-uy[k]+ux[k]*ux[k]+uy[k]*uy[k])+9.0*ux[k]*uy[k]);
         f8[i][j] = 1.0/36.0*rho[i][j]*(1.0+3.0*(ux[k]-uy[k]+ux[k]*ux[k]+uy[k]*uy[k])-9.0*ux[k]*uy[k]);

        }
    }

//StreamCollide loop
for(t=1;t<tend;t++)
{







//Boundary conditions
//Periodic

//WEST case
  for(j=0;j<=my+1;j++)
  {
    f1[0][j] = f1[mx][j];
   f5[0][j] = f5[mx][j];
   f8[0][j] = f8[mx][j];

//EAST case
   f3[mx+1][j] = f3[1][j];
   f6[mx+1][j] = f6[1][j];
   f7[mx+1][j] = f7[1][j];
  }

//NORTH case
  for(i=0;i<=mx+1;i++)
  {


   f4[i][my+1]=f4[i][1];
   f7[i][my+1]=f7[i][1];
   f8[i][my+1]=f8[i][1];

//SOUTH case
   f2[i][0]=f2[i][my];
   f5[i][0]=f5[i][my];
   f6[i][0]=f6[i][my];
  }
//Streaming

//forward
  for(j=1;j<=my;j++)
  {
      for(i=1;i<=mx;i++)
      {
        f3[i][j]=f3[i+1][j];
        f4[i][j]=f4[i][j+1];
        f7[i][j]=f7[i+1][j+1];
      }
   for(i=mx;i>=1;i--)
   {
    f8[i][j]=f8[i-1][j+1];
   }
  }
//backward
  for(j=my ; j>=1;j--)
  {
   for(i=mx;i>=1;i--)
   {
    f1[i][j]=f1[i-1][j];
    f2[i][j]=f2[i][j-1];
    f5[i][j]=f5[i-1][j-1];
   }
   for(i=1 ;i<=mx;i++)
   {
    f6[i][j]=f6[i+1][j-1];
   }
  }

  //Compute Rho and mu

for(j=1;j<=my;j++)
{
   for(i=1 ; i<=mx;i++)
   {

    rho[i][j]=f0[i][j]+f1[i][j]+f2[i][j]+f3[i][j]+f4[i][j]+f5[i][j]+f6[i][j]+f7[i][j]+f8[i][j];

   }
}

  for(j=1;j<=my;j++)
  {
   for(i=1;i<=mx;i++)
   {

      Lap=0.5*(rho[mod(i,mx)+1][j]-2*rho[i][j]+rho[mx-mod(mx+1-i,mx)][j]+rho[i][mod(j,my)+1]-2*rho[i][j]+rho[i][my-mod(my+1-j,my)]);



    mu0=4*beta*(rho[i][j]-rho0L)*(rho[i][j]-rho0G)*(rho[i][j]-(rho0G+rho0L)*0.5);

	mu[i][j]=mu0-kappa*Lap;

   }
  }

for(i=1;i<=mx;i++)
{
 for(j=1;j<my;j++)
 {



//Central differences

	gradRhoC1=0.5*(rho[mod(i,mx)+1][j]-rho[mx-mod(mx+1-i,mx)][j]);
	gradRhoC2=0.5*(rho[i][mod(j,my)+1]-rho[i][my-mod(my+1-j,my)]);
    gradRhoC3=0.5*(rho[mx-mod(mx+1-i,mx)][j]-rho[mod(i,mx)+1][j]);
    gradRhoC4=0.5*(rho[i][my-mod(my+1-j,my)]-rho[i][mod(j,my)+1]);
    gradRhoC5=0.5*(rho[mod(i,mx)+1][mod(j,my)+1]-rho[mx-mod(mx+1-i,mx)][my-mod(my+1-j,my)]);
    gradRhoC6=0.5*(rho[mx-mod(mx+1-i,mx)][mod(j,my)+1]-rho[mod(i,mx)+1][my-mod(my+1-j,my)]);
    gradRhoC7=0.5*(rho[mx-mod(mx+1-i,mx)][my-mod(my+1-j,my)]-rho[mod(i,mx)+1][mod(j,my)+1]);
    gradRhoC8=0.5*(rho[mod(i,mx)+1][my-mod(my+1-j,my)]-rho[mx-mod(mx+1-i,mx)][mod(j,my)+1]);

    gradMuC1=0.5*(mu[mod(i,mx)+1][j]-mu[mx-mod(mx+1-i,mx)][j]);
    gradMuC2=0.5*(mu[i][mod(j,my)+1]-mu[i][my-mod(my+1-j,my)]);
    gradMuC3=0.5*(mu[mx-mod(mx+1-i,mx)][j]-mu[mod(i,mx)+1][j]);
    gradMuC4=0.5*(mu[i][my-mod(my+1-j,my)]-mu[i][mod(j,my)+1]);
    gradMuC5=0.5*(mu[mod(i,mx)+1][mod(j,my)+1]-mu[mx-mod(mx+1-i,mx)][my-mod(my+1-j,my)]);
    gradMuC6=0.5*(mu[mx-mod(mx+1-i,mx)][mod(j,my)+1]-mu[mod(i,mx)+1][my-mod(my+1-j,my)]);
    gradMuC7=0.5*(mu[mx-mod(mx+1-i,mx)][my-mod(my+1-j,my)]-mu[mod(i,mx)+1][mod(j,my)+1]);
    gradMuC8=0.5*(mu[mod(i,mx)+1][my-mod(my+1-j,my)]-mu[mx-mod(mx+1-i,mx)][mod(j,my)+1]);

//Central part for the force: [grad[rho*cs^2]-rho*grad[mu]]

    FC1=1/3*gradRhoC1-rho[i][j]*gradMuC1;
    FC2=1/3*gradRhoC2-rho[i][j]*gradMuC2;
    FC3=1/3*gradRhoC3-rho[i][j]*gradMuC3;
    FC4=1/3*gradRhoC4-rho[i][j]*gradMuC4;
    FC5=1/3*gradRhoC5-rho[i][j]*gradMuC5;
    FC6=1/3*gradRhoC6-rho[i][j]*gradMuC6;
    FC7=1/3*gradRhoC7-rho[i][j]*gradMuC7;
    FC8=1/3*gradRhoC8-rho[i][j]*gradMuC8;


//Upwind derivatives

    gradRhoU1=0.5*(-rho[mod(i+1,mx)+1][j]+4*rho[mod(i,mx)+1][j]-3*rho[i][j]);
    gradRhoU2=0.5*(-rho[i][mod(j+1,my)+1]+4*rho[i][mod(j,my)+1]-3*rho[i][j]);
    gradRhoU3=0.5*(-rho[mx-mod(mx+2-i,mx)][j]+4*rho[mx-mod(mx+1-i,mx)][j]-3*rho[i][j]);
    gradRhoU4=0.5*(-rho[i][my-mod(my+2-j,my)]+4*rho[i][my-mod(my+1-j,my)]-3*rho[i][j]);
    gradRhoU5=0.5*(-rho[mod(i+1,mx)+1][mod(j+1,my)+1]+4*rho[mod(i,mx)+1][mod(j,my)+1]-3*rho[i][j]);
    gradRhoU6=0.5*(-rho[mx-mod(mx+2-i,mx)][mod(j+1,my)+1]+4*rho[mx-mod(mx+1-i,mx)][mod(j,my)+1]-3*rho[i][j]);
    gradRhoU7=0.5*(-rho[mx-mod(mx+2-i,mx)][my-mod(my+2-j,my)]+4*rho[mx-mod(mx+1-i,mx)][my-mod(my+1-j,my)]-3*rho[i][j]);
    gradRhoU8=0.5*(-rho[mod(i+1,mx)+1][my-mod(my+2-j,my)]+4*rho[mod(i,mx)+1][my-mod(my+1-j,my)]-3*rho[i][j]);

    gradMuU1=0.5*(-mu[mod(i+1,mx)+1][j]+4*mu[mod(i,mx)+1][j]-3*mu[i][j]);
    gradMuU2=0.5*(-mu[i][mod(j+1,my)+1]+4*mu[i][mod(j,my)+1]-3*mu[i][j]);
    gradMuU3=0.5*(-mu[mx-mod(mx+2-i,mx)][j]+4*mu[mx-mod(mx+1-i,mx)][j]-3*mu[i][j]);
    gradMuU4=0.5*(-mu[i][my-mod(my+2-j,my)]+4*mu[i][my-mod(my+1-j,my)]-3*mu[i][j]);
    gradMuU5=0.5*(-mu[mod(i+1,mx)+1][mod(j+1,my)+1]+4*mu[mod(i,mx)+1][mod(j,my)+1]-3*mu[i][j]);
    gradMuU6=0.5*(-mu[mx-mod(mx+2-i,mx)][mod(j+1,my)+1]+4*mu[mx-mod(mx+1-i,mx)][mod(j,my)+1]-3*mu[i][j]);
    gradMuU7=0.5*(-mu[mx-mod(mx+2-i,mx)][my-mod(my+2-j,my)]+4*mu[mx-mod(mx+1-i,mx)][my-mod(my+1-j,my)]-3*mu[i][j]);
    gradMuU8=0.5*(-mu[mod(i+1,mx)+1][my-mod(my+2-j,my)]+4*mu[mod(i,mx)+1][my-mod(my+1-j,my)]-3*mu[i][j]);

//Upwind part for the force: ci*[grad[rho*cs^2]-rho*grad[mu]]

            FU1=1/3*gradRhoU1-rho[i][j]*gradMuU1;
            FU2=1/3*gradRhoU2-rho[i][j]*gradMuU2;
            FU3=1/3*gradRhoU3-rho[i][j]*gradMuU3;
            FU4=1/3*gradRhoU4-rho[i][j]*gradMuU4;
            FU5=1/3*gradRhoU5-rho[i][j]*gradMuU5;
            FU6=1/3*gradRhoU6-rho[i][j]*gradMuU6;
            FU7=1/3*gradRhoU7-rho[i][j]*gradMuU7;
            FU8=1/3*gradRhoU8-rho[i][j]*gradMuU8;

            //Total central difference (sum over the lattice)


    gradRhoCx=1/3*(gradRhoC1-gradRhoC3)+1/12*(gradRhoC5-gradRhoC6+gradRhoC8-gradRhoC7);
    gradRhoCy=1/3*(gradRhoC2-gradRhoC4)+1/12*(gradRhoC5+gradRhoC6-gradRhoC7-gradRhoC8);

    gradMuCx=1/3*(gradMuC1-gradMuC3)+1/12*(gradMuC5-gradMuC6+gradMuC8-gradMuC7);
    gradMuCy=1/3*(gradMuC2-gradMuC4)+1/12*(gradMuC5+gradMuC6-gradMuC7-gradMuC8);


    FCx=1/3*gradRhoCx-rho[i][j]*gradMuCx;
    FCy=1/3*gradRhoCy-rho[i][j]*gradMuCy;


    gradRhoUx=1/3*(gradRhoU1-gradRhoU3)+1/12*(gradRhoU5-gradRhoU6-gradRhoU7+gradRhoU8);
    gradRhoUy=1/3*(gradRhoU2-gradRhoU4)+1/12*(gradRhoU5+gradRhoU6-gradRhoU7-gradRhoU8);

    gradMuUx=1/3*(gradMuU1-gradMuU3)+1/12*(gradMuU5-gradMuU6-gradMuU7+gradMuU8);
    gradMuUy=1/3*(gradMuU2-gradMuU4)+1/12*(gradMuU5+gradMuU6-gradMuU7-gradMuU8);


    FUx=1/3*gradRhoUx-rho[i][j]*gradMuUx;
    FUy=1/3*gradRhoUy-rho[i][j]*gradMuUy;

// Mixed differences

            FM1=0.5*(FC1+FU1);
            FM2=0.5*(FC2+FU2);
            FM3=0.5*(FC3+FU3);
            FM4=0.5*(FC4+FU4);
            FM5=0.5*(FC5+FU5);
            FM6=0.5*(FC6+FU6);
            FM7=0.5*(FC7+FU7);
            FM8=0.5*(FC8+FU8);

            FMx=0.5*(FCx+FUx);
            FMy=0.5*(FCy+FUy);


//Velocity

      u[i][j]=(f1[i][j]-f3[i][j]+f5[i][j]- f6[i][j]-f7[i][j]+f8[i][j]+0.5*FCx)/rho[i][j];
      v[i][j]=(f5[i][j]+f2[i][j]+f6[i][j]- f7[i][j]-f4[i][j]-f8[i][j]+0.5*FCy)/rho[i][j];


      ux[k]=u[i][j];
      uy[k]=v[i][j];

//Equilibria


             f0zero = 4/9*rho[i][j]*(1-1.5*(ux[k]*ux[k]+uy[k]*uy[k]));
             f1zero = 1/9*rho[i][j]*(1+3*ux[k]+3*ux[k]*ux[k]-1.5*uy[k]*uy[k]);
             f2zero = 1/9*rho[i][j]*(1+3*uy[k]+3*uy[k]*uy[k]-1.5*ux[k]*ux[k]);
             f3zero = 1/9*rho[i][j]*(1-3*ux[k]+3*ux[k]*ux[k]-1.5*uy[k]*uy[k]);
             f4zero = 1/9*rho[i][j]*(1-3*uy[k]+3*uy[k]*uy[k]-1.5*ux[k]*ux[k]);
             f5zero = 1/36*rho[i][j]*(1+3*(ux[k]+uy[k]+ux[k]*ux[k]+uy[k]*uy[k])+9*ux[k]*uy[k]);
             f6zero = 1/36*rho[i][j]*(1+3*(-ux[k]+uy[k]+ux[k]*ux[k]+uy[k]*uy[k])-9*ux[k]*uy[k]);
             f7zero = 1/36*rho[i][j]*(1+3*(-ux[k]-uy[k]+ux[k]*ux[k]+uy[k]*uy[k])+9*ux[k]*uy[k]);
             f8zero = 1/36*rho[i][j]*(1+3*(ux[k]-uy[k]+ux[k]*ux[k]+uy[k]*uy[k])-9*ux[k]*uy[k]);

//'barred' Equilibria

             f0zeroBar=f0zero+3/2*(ux[k]*FCx+uy[k]*FCy)*f0zero/rho[i][j];
             f1zeroBar=f1zero-3/2*(FC1-ux[k]*FCx-uy[k]*FCy)*f1zero/rho[i][j];
             f2zeroBar=f2zero-3/2*(FC2-ux[k]*FCx-uy[k]*FCy)*f2zero/rho[i][j];
             f3zeroBar=f3zero-3/2*(FC3-ux[k]*FCx-uy[k]*FCy)*f3zero/rho[i][j];
             f4zeroBar=f4zero-3/2*(FC4-ux[k]*FCx-uy[k]*FCy)*f4zero/rho[i][j];
             f5zeroBar=f5zero-3/2*(FC5-ux[k]*FCx-uy[k]*FCy)*f5zero/rho[i][j];
             f6zeroBar=f6zero-3/2*(FC6-ux[k]*FCx-uy[k]*FCy)*f6zero/rho[i][j];
             f7zeroBar=f7zero-3/2*(FC7-ux[k]*FCx-uy[k]*FCy)*f7zero/rho[i][j];
             f8zeroBar=f8zero-3/2*(FC8-ux[k]*FCx-uy[k]*FCy)*f8zero/rho[i][j];

//Collisions and force

            f0[i][j] = f0[i][j]-(f0[i][j]-f0zeroBar)/(tau+0.5)-3*(ux[k]*FMx+uy[k]*FMy)*f0zero/rho[i][j];
            f1[i][j] = f1[i][j]-(f1[i][j]-f1zeroBar)/(tau+0.5)+3*(FM1-ux[k]*FMx-uy[k]*FMy)*f1zero/rho[i][j];
            f2[i][j] = f2[i][j]-(f2[i][j]-f2zeroBar)/(tau+0.5)+3*(FM2-ux[k]*FMx-uy[k]*FMy)*f2zero/rho[i][j];
            f3[i][j] = f3[i][j]-(f3[i][j]-f3zeroBar)/(tau+0.5)+3*(FM3-ux[k]*FMx-uy[k]*FMy)*f3zero/rho[i][j];
            f4[i][j] = f4[i][j]-(f4[i][j]-f4zeroBar)/(tau+0.5)+3*(FM4-ux[k]*FMx-uy[k]*FMy)*f4zero/rho[i][j];
            f5[i][j] = f5[i][j]-(f5[i][j]-f5zeroBar)/(tau+0.5)+3*(FM5-ux[k]*FMx-uy[k]*FMy)*f5zero/rho[i][j];
            f6[i][j] = f6[i][j]-(f6[i][j]-f6zeroBar)/(tau+0.5)+3*(FM6-ux[k]*FMx-uy[k]*FMy)*f6zero/rho[i][j];
            f7[i][j] = f7[i][j]-(f7[i][j]-f7zeroBar)/(tau+0.5)+3*(FM7-ux[k]*FMx-uy[k]*FMy)*f7zero/rho[i][j];
            f8[i][j] = f8[i][j]-(f8[i][j]-f8zeroBar)/(tau+0.5)+3*(FM8-ux[k]*FMx-uy[k]*FMy)*f8zero/rho[i][j];



 }
}
}
ofstream file;
file.open("out.m");
file << "out=[";
for(j=1;j<=my;j++)
{
    for(i=1;i<=mx;i++)
    {
        file << rho[i][j] << " " ;
    }
file << endl << ";";
}

file << "]";
file.close();
return(0);

}


template<typename V>
V mod(V a, V b)
{
    return (a % b + b) % b;
}
