#ifndef GLOBAL_H
# define GLOBAL_H

#define DECLARE_RULE4 (Class, action) \
	Class (const Class& other) = action; \
	Class (Class&& other) = action; \
	Class& operator= (const Class& other) = action; \
	Class& operator= (Class&& other) = action; 

#define DISABLE_COPY (Class) \
 DECLARE_RULE4 (Class, delete);
#endif // GLOBAL_H