typedef short Boolean; 
#define TRUE 1 
#define FALSE 0 

typedef char *string; 

#define CAST(t,e) ((t)(e)) 
#define TYPED_MALLOC(t) CAST(t*,malloc(sizeof(t))) 

