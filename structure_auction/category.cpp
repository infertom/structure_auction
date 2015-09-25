#include "Category.h"

istream &operator>>(istream &stream, Category &c)
{
    int pid;
    string name;
    stream>>pid>>name;
    c.setParent(pid);
    c.setName(name);

    return stream;
}

Category::Category(void):number(0),parent(0),name("")
{

}

Category::Category(int parent, string name)
{
    this->parent = parent;
    this->name = name;
}

int Category::getNumber(void) const
{
    return number;
}

int Category::getParent(void) const
{
    return parent;
}

string Category::getName(void) const
{
    return name;
}

void Category::setNumber(int number)
{
    this->number = number;
}

void Category::setParent(int parent)
{
    this->parent = parent;
}

void Category::setName(string name)
{
    this->name = name;
}

void Category::addSubCategory(Category * c)
{
    sub_categories.insert(c);
}

void Category::addItem(int it)
{
    items.insert(it);
}

void Category::findOfferings (Listing::iterator start, Listing::iterator finish, Listing &matches)
{
    for ( set<int>::iterator it = items.begin(); it != items.end(); it++){
        for ( Listing::iterator i = start; i != finish; i++){
            if ( (*it) == (*i)->getNumber() ) {
				matches.add(*i);
				break;
			}
        }
    }
}

void Category::findOfferingsRecursive (Listing::iterator start, Listing::iterator finish, Listing &matches)
{
    for ( set<int>::iterator it = items.begin(); it != items.end(); it++){
        for ( Listing::iterator i = start; i != finish; i++){
            if ( (*it) == (*i)->getNumber() ) {
				matches.add(*i);
				break;
			}
        }
    }
    for ( set<Category*>::iterator it = sub_categories.begin(); it != sub_categories.end(); it++){
        (*it)->findOfferingsRecursive(start, finish, matches);
    }
}

set<int>::iterator Category::itemsBegin()
{
    return items.begin();
}

set<int>::iterator Category::itemsEnd()
{
    return items.end();
}

set<Category*>::iterator Category::subCategoriesBegin()
{
    return sub_categories.begin();
}

set<Category*>::iterator Category::subCategoriesEnd()
{
    return sub_categories.end();
}

bool Category::operator==(const Category& rhs)
{
    return (number == rhs.getNumber());
}
