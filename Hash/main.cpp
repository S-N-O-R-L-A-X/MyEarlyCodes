#include <iostream>
#define maxsize 3000
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

class Hash_table
{
public:
    Hash_table(int size=0);
	void clear();
	Error_code insert(const Record &new_entry);
	Error_code retrieve(const Key &target,Record &found) const;
	void search(const Key &target) const;
	Error_code remove(const Key &target,Record &found);
    int Hash(const Record &new_entry) const;
    int Hash(const Key &new_entry) const;
private:
	Record table[maxsize];
	int hash_size;
};


int main()
{
    int n,m;
    cin>>n>>m;
    Hash_table x(n);
    x.clear();
    for(int i=0;i<m;i++)
    {
        int key,value;
        cin>>key>>value;
        Record tmp(key,value);
        if(x.insert(tmp)==overflow)
            break;
    }
    int a,b;
    cin>>a;
    Key key1(a);
    x.search(key1);
    cin>>b;
    Key key2(b);

    x.search(key2);

    return 0;
}

Key::Key(int x)
{
    key=x;
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
	return x.the_key()!=y.the_key();
}

bool operator == (const Record &x,const Record &y)
{
	return x.the_key()==y.the_key();
}

Hash_table::Hash_table(int size)
{
    hash_size=size;
}

void Hash_table::clear()
{
	for(int i=0;i<hash_size;i++)
    {
		Record tmp;
		table[i]=tmp;
	}
}




int Hash_table::Hash(const Record &new_entry) const
{
	return new_entry.the_key()%hash_size;
}


int Hash_table::Hash(const Key &new_entry) const
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
	if(retrieve((Record)new_entry,(Record &)new_entry)==success)
        return duplicate_error;
	while(table[probe]!=0&&table[probe]!=-1&&probe_count<(hash_size)/2)
    {// empty because delete // Is the location empty?  // Has overflow occurred?
		probe_count++;
		probe=(probe+increment)%hash_size;
		increment+=2; // Prepare increment for next iteration.Ã¿´ÎµÝÔö2¡£
	}
	if(table[probe]==0)
        table[probe]=new_entry;
    else
    {
        if(table[probe]==-1)
            table[probe]=new_entry;
        else
            result=overflow; // The table is full.
    }

	return result;
}

Error_code Hash_table::retrieve(const Key &target, Record &found) const
{
	int probe_count,// Counter to be sure that table is not full.
	increment,// Increment used for quadratic probing.
	probe; // Position currently probed in the hash table.
	probe=Hash(target);
	probe_count=0;
	increment=1;
	while(table[probe]!=0&&table[probe].the_key()!=target.the_key()&&probe_count<=(hash_size)/2)
    { //Is the location empty?  // not found // Has overflow occurred?
        probe_count++;
        probe=(probe+increment)%hash_size;
        increment+=2; // Prepare increment for next iteration.
    }
    if(table[probe].the_key() == target.the_key())
    {
        found=table[probe];
        return success;
	}
    return not_present;
}

void Hash_table::search(const Key &target) const
{
    int probe_count,increment,// Increment used for quadratic probing.
	probe; // Position currently probed in the hash table.
	probe=Hash(target);
	probe_count=0;
	increment=1;
	cout<<probe<<' ';
	while(table[probe]!=0&&table[probe].the_key()!=target.the_key()&&probe_count<(hash_size)/2)//needs to be modified
    { //Is the location empty?  // not found // Has overflow occurred?
        probe_count++;
        probe=(probe+increment)%hash_size;
        cout<<probe<<' ';
        increment+=2; // Prepare increment for next iteration.
    }
    if(table[probe].the_key()==target.the_key())
        cout<<table[probe].the_key()<<' '<<table[probe].the_other()<<endl;
	else
        cout<<"NULL"<<endl;
}

Error_code Hash_table::remove(const Key &target, Record &found)
{
    int probe_count, // Counter to be sure that table is not full.
	increment, // Increment used for quadratic probing.
	probe; // Position currently probed in the hash table.
	probe=Hash(target);
	probe_count=0;
	increment=1;
	while(table[probe]!=0&&table[probe].the_key()!=target.the_key()&&probe_count<(hash_size)/2)
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
	return not_present;
}


