#include <cstring>
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
//#include <mpi.h>
#include <string>
#include <sstream>


using namespace std;


const double e[19][3]={{0,0,0},{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1},{1,1,0},{-1,1,0},{1,-1,0},{-1,-1,0},{0,1,1},{0,-1,1},{0,1,-1},{0,-1,-1},{1,0,1},{-1,0,1},{1,0,-1},{-1,0,-1}};

const double t[19]={1.0/3.0,1.0/18.0,1.0/18.0,1.0/18.0,1.0/18.0,1.0/18.0,1.0/18.0,1.0/36.0,1.0/36.0,1.0/36.0,1.0/36.0,1.0/36.0,1.0/36.0,1.0/36.0,1.0/36.0,1.0/36.0,1.0/36.0,1.0/36.0,1.0/36.0};

const int com[19]={0,2,1,4,3,6,5,10,9,8,7,14,13,12,11,18,17,16,15};
class wet
{

	int ProcessN; //Number of nodes the processor is dealing with
	
	double *C , *mu , *p, *rho; //Assigning memory space to the composition 
	
	double (*u)[3];
	
	int (*d)[18]; //Assigning memory for neibour arrays
	
	int k, k1,k2; //Starting and finishing k values
	
	double t0,t1,t2; //Weightings used to ensure anisotropy

	double (*dC)[3], (*dmu)[3], (*dp)[3], (*drho)[3], d2C; // Gradients of equiliberium variables
	
	int Lx,Ly,Lz; // Size of simulation box
	
	double ux,uy,uz; //Initial Drop velocity
	
	int xk,yk,zk; //Positions
	
	int xcentre,ycentre,zcentre,R; //Drop position and drop radius
	
	int a,i ;//Discrete velocity index and cartesian index
	
	double (*gamma)[19], (*dgamma)[19]; //Gamma 
	
	double (*g)[19], (*h)[19]; //The single particle probability functions
	
	double (*ge)[19], (*he)[19]; //Equiliberium functions
	
	double (*gc)[19], (*hc)[19]; //post collision functions
	
	double (*geq)[19], (*heq)[19]; //Equiliberium functions
	
	
	
	int dimensions; //Number of dimensions the problem is being run in 
	
	double B, kappa; //Constants in free Energy

	double cs2;//cs squared in literature
	
	double dx , dt ; //Lattice spacing both set to one at the moment
	
	double rho1 ,rho2 ; // Liquid and gas densities
	
	string folder; //Holds the name of the folder to which inputs should be written
	
	long int st;//equation step
	
	long int Neqst; //Number of iteration steps

	int Q; // Number of velocity dicridations


	void initialisemoments();
	void computecoordinates(int);
	void initialise();
	void neibour(int);
	void readinput();
	void equiliberiumg(int);
	void equiliberiumh(int);
	void writemoments(long int);
	void computemoments();
	template<typename V> V mod(V,V);
	
	
	public:
	
		void algorithm();
		wet(void);
		
	
	
	









};

template<typename V>
V wet::mod(V a, V b)
{
    return (a % b + b) % b;
}