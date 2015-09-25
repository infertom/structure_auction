#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
#include <vector>
#include <set>

#include "Listing.h"

using namespace std;

class Category;

istream &operator>>(istream &stream, Category &c);

class Category {

private:
	int number;
	int parent;
	string name;

	set<Category*> sub_categories;
	set<int> items;

public:
	
	Category(void);
	Category(int parent, string name);

	virtual int getNumber(void) const;
	virtual int getParent(void) const;
	virtual string getName(void) const;
	
	virtual void setNumber(int);
	virtual void setParent(int);
	virtual void setName(string);

	virtual void addSubCategory(Category*);
	virtual void addItem(int);

    virtual void findOfferings (Listing::iterator start, 
					Listing::iterator finish, Listing &matches);
    virtual void findOfferingsRecursive (Listing::iterator start, 
					Listing::iterator finish, Listing &matches);

	virtual set<int>::iterator itemsBegin();
	virtual set<int>::iterator itemsEnd();
	virtual set<Category*>::iterator subCategoriesBegin();
	virtual set<Category*>::iterator subCategoriesEnd();

	virtual bool operator==(const Category& rhs);

};

#endif
