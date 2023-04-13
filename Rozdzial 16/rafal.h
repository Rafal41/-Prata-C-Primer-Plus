#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define PARZ(X) ((X) % 2 == 0 ? 1 : 0)
#define ABS(X) ((X) < 0 ? (-X) : (X))
#define ZNAK(X) ((X) == '+' || (X) == "-" ? 1 : 0)
#define SRHARM(X,Y) (1/(1/(X) + 1/(Y)))

#define TYLKOSPRAWDZAM
#define TEMPOFF

#define NUMTYP(X) _GENERIC ((X),\
int: "int",\
short int: "short int",\
unsigned short int: "unsigned short int",\
unsigned int: "unsigned",\
long int: "long int",\
unsigned long: "unsigned long",\
long long int: "long long int",\
unsigned long long int: "unsigned long long int",\
float: "float",\
double: "double",\
long double: "long double"\
)

