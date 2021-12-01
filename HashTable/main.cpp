#include <iostream>

using namespace std;

enum Error_code{not_present,overflow,duplicate_error,success};

class Key
{
	int key;
public:
	Key(int x=0);
	int the_key() const;
};

bool operator == (const Key &x, const Key &y);


class Record
{
public:
	operator Key();// implicit conversion from Record to Key .
	Record(int x=0,int y=0);
	int the_key() const;
	int the_other() const;
private:
	int key;
	int other;
};

bool operator !=(const Record &x,const Record &y);
bool operator ==(const Record &x,const Record &y);

const int hash_size=97;

class Hash_table
{
public:
	void clear();
	Error_code insert(const Record &new_entry);
	Error_code retrieve(const Key &target,Record &found) const;
	Error_code remove(const Key &target,Record &found);
private:
	Record table[hash_size];
};

int hash(const Record &new_entry);
int hash(const Key &new_entry);

int main()
{
    int n,m;
    cin>>n>>m;

    return 0;
}

int Key::the_key() const
{
	return key;
}

bool operator == (const Key &x,const Key &y)
{
	return x.the_key()==y.the_key();
}

Record::Record(int x, int y)
{
	key=x;
	other=y;
}



int Record::the_key() const
{
	return key;
}



int Record::the_other() const
{
	return other;
}

Record::operator Key()
{
	Key tmp(key);
	return tmp;
}



bool operator != (const Record &x,const Record &y)
{
	return x.the_key( ) != y.the_key( );
}



bool operator == (const Record &x,const Record &y)
{
	return x.the_key( ) == y.the_key( );
}

void Hash_table::clear()
{
	for(int i=0;i<hash_size;i++)
    {
		Record tmp;
		table[i]=tmp;
	}
}


int Hash(const Record &new_entry)
{
	return new_entry.the_key()%hash_size;
}


int Hash(const Key &new_entry)
{
	return new_entry.the_key()%hash_size;
}

Error_code Hash_table::insert(const Record &new_entry)
{
	Error_code result=success;
	int probe_count, // Counter to be sure that table is not full.
	increment, // Increment used for quadratic probing.
	probe; // Position currently probed in the hash table.
	probe=Hash(new_entry);
	probe_count=0;
	increment=1;
	if(retrieve(new_entry,(Record)new_entry)==success)
        return duplicate_error;
	while(table[probe]!=0&&table[probe]!=-1&&probe_count<(hash_size+1)/2)
    {// empty because delete // Is the location empty?  // Has overflow occurred?
		probe_count++;
		probe=(probe+increment)%hash_size;
		increment+=2; // Prepare increment for next iteration.Ã¿´ÎµÝÔö2¡£
	}
	if(table[probe]==0)
        table[probe]=new_entry;
	if(table[probe]==-1)
        table[probe]=new_entry;
	// Insert new entry.
	else
        result=overflow; // The table is full.
	return result;
}

Error_code Hash_table::retrieve(const Key &target, Record &found) const{
	int probe_count,// Counter to be sure that table is not full.
	increment,// Increment used for quadratic probing.
	probe; // Position currently probed in the hash table.
	probe=Hash(target);
	probe_count=0;
	increment=1;
	while(table[probe]!=0&&table[probe].the_key()!=target.the_key()&&probe_count(hash_size+1)/2)//Is the location empty?  // not found
    { // Has overflow occurred?
        probe_count++;
        probe=(probe+increment)%hash_size;
        increment+=2; // Prepare increment for next iteration.
    }
    if(table[probe].the_key() == target.the_key())
    {
        found=table[probe];
        return success;
	}
	else return not_present;
}

Error_code Hash_table::remove(const Key &target, Record &found)
{
    int probe_count, // Counter to be sure that table is not full.
	increment, // Increment used for quadratic probing.
	probe; // Position currently probed in the hash table.
	probe=Hash(target);
	probe_count=0;
	increment=1;
	while(table[probe]!=0&&table[probe].the_key()!=target.the_key()&&probe_count<(hash_size+1)/2)
    { // Is the location empty?   // not found     // Has overflow occurred?
		probe_count++;
		probe=(probe+increment)%hash_size;
		increment+=2;// Prepare increment for next iteration.
	}
    if(table[probe].the_key()==target.the_key())
    {
		found=table[probe];
		table[probe]=-1;  //attention
		return success;
	}
	else return not_present;
}


