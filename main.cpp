
#include <iostream>
#include <cstring>
using namespace std;


class MyString
{
    int Size ;
    char *strArr ;
public:

//default constructor
    MyString():strArr(NULL),Size(0) {}

// Constructor with parameters
    MyString(int s,string st):Size(s)
    {
        strArr = new char[s];
        for ( int i = 0 ; i < Size ; i++)
            strArr[i] = st[i];
    }

//copy constructor
    MyString(const MyString& obj)
    {
        Size = obj.Size ;
        strArr = new char [Size];
        for ( int i = 0 ; i < Size ; i++)
            strArr[i] = obj.strArr[i];
    }

//destructor
    ~MyString()
    {
        if (Size>0)
            delete [] strArr;
        Size=0;
        strArr=NULL;
    }

//Removes the last element from the MyString object
    void Remove()
    {
        Size-=1;
        if (Size<0)
            Size=0;
    }

//Accepts a character as an argument
//and adds it to the end of the MyString object
    void Add(char item)
    {
        Size++;
        strArr[Size-1] = item ;
    }

//Returns the length of the MyString
    int Length()
    {
        return Size ;
    }

//copies the MyString object to a character array
    void Copy (int pos, int len)
    {
        char str[len-pos+1];
        for (int i= pos,j=0;i<len+pos; i++,j++)
        {
            str[j]=this->strArr[i];
        }
        cout<<str<<endl;
    }
//swaps the two MyString objects.
    void Swap(MyString &obj)
    {
        MyString Temp(this->Size,this->strArr);
        this->strArr=obj.strArr;
        this->Size=obj.Size;
        obj=Temp;
    }
//Compare (string1, string2)
    int Compare(MyString &mstring)
    {
        if (Size < mstring.Size)
            return -1 ;
        else if (Size > mstring.Size)
            return 1 ;
        else
            return 0 ;
    }

//Substring (startIndex, endIndex)
//Returns a new string that is a substring of this string
    void Substring (int startIndex, int endIndex)
    {
        for (int i= startIndex ; i<=endIndex ; i++)
        {
            cout << strArr[i];

        }
    }

//Returns a copy of this string with leading
// and trailing white space removed
    void Trim()
    {
        for (int i=0 ; i<Size ; i++)
        {
            if (strArr[i] != ' ')
            {
                cout<<strArr[i];
            }
            else
                continue;
        }
    }

//Returns a copy of this string converted to uppercase
//return the original string,If no conversions
//are necessary
    void ToLowerCase()
    {
        for (int i=0 ; i<Size ; i++)
        {
            if (strArr[i] >= 'a' && strArr[i] <= 'z')
            {
                strArr[i] = strArr[i] - 32 ;
                cout << strArr[i] ;
            }
            else
                cout << strArr[i] ;
        }
    }

//Returns a copy of this string converted to lowercase.
//return the original string
//If no conversions are necessary
    void ToUpperCase()
    {
        for (int i=0 ; i<Size ; i++)
        {
            if (strArr[i] >= 'A' && strArr[i] <= 'Z')
            {
                strArr[i] = strArr[i] + 32 ;
                cout << strArr[i] ;
            }
            else
                cout << strArr[i] ;
        }
    }

//Returns the index of the first occurrence
//of the specified character
    void IndexOf (char ch)
    {
        for (int i =0 ; i<Size ; i++)
        {
            if (strArr[i] == ch)
            {
                cout << "Index of the first occurrence of the specified character is: " << i << endl ;
                break ;
            }

            else
                continue ;
        }
    }

//: Returns the index of the last occurrence of the specified character
    void LastIndexOf (char ch)
    {
        for (int i =Size-1; i>=0; i--)
        {
            if (strArr[i] == ch)
            {
                cout << "Index of the last occurrence of the specified character is: " << i << endl ;
                break ;
            }

            else
                continue ;
        }
    }

// Returns a new string resulting from replacing all occurrences
//of oldChar in this string with newChar
    void Replace (char oldCharacter, char newCharacter)
    {
        for (int i =0 ; i<Size ; i++)
        {
            if (strArr[i] == oldCharacter)
            {
                strArr[i] = newCharacter ;
                cout << strArr[i];
            }
            else
                cout << strArr[i];

        }
    }
//Accsesores
    string Show()
    {
        string s="";
        for(int i=0; i<Size; i++)
        {
            s+=strArr[i];
        }
        return s;
    }
    void operator = (const MyString &obj)
    {
        Size=obj.Size;
        strArr=new char[Size];
        for(int i=0; i<Size; i++)
            strArr[i]=obj.strArr[i];
    }
    MyString operator +(const MyString &obj)
    {
        string s1="",s2="";
        for(int i=0; i<Size; i++)
            s1+=strArr[i];
        for(int i=0; i<obj.Size; i++)
            s2+=obj.strArr[i];
        s1+=s2;
        MyString Tempstr(s1.size(),s1);
        return Tempstr;
    }

};

int main()
{
    string s1;
    cout<<"Enter a string: "
        ;
    getline(cin,s1);
    int Size=s1.size();
    MyString strObj1(Size,s1);
    bool flag = false;
    int choice ;
    while(!flag)
    {
        cout << "Menu:\n";
        cout << "1- Remove the last element\n";
        cout << "2- Add a character\n";
        cout << "3- Length of the string\n";
        cout << "4- Copy the string form certain position and length\n";
        cout << "5- Swap\n" ;
        cout << "6- Concatenate\n";
        cout << "7- Compare two strings\n";
        cout << "8- Substring\n" ;
        cout << "9- Trim\n" ;
        cout << "10- Convert to Upper case\n";
        cout << "11- Convert to Lower case\n";
        cout << "12- First index of first occurrence\n" ;
        cout << "13- Last index of first occurrence\n";
        cout << "14- Replace\n";
        cout << "15- To Print your stirng\n";
        cout << "0- EXIT\n";
        cout << "---------------------------------------------------------------------------\n" ;
        cout << "Enter the choice you want to execute ..\n";
        cin >> choice ;
        if (choice == 1 )
        {
            if(Size!=0)
            {
                strObj1.Remove() ;
                Size--;
                cout<<"done.. last element is removed successfully.";
                cout<<"\nyour string: "<<strObj1.Show()<<endl;
            }
            else
                cout<<"All characters have already been deleted..!"<<endl;

        }
        else if (choice == 2)
        {
            char ch ;
            cout << "Enter the character you want to add\n" ;
            cin >> ch ;
            strObj1.Add(ch) ;
            cout<<"done.. character is added successfully.";
            cout<<"\nyour string: "<<strObj1.Show()<<endl;

        }
        else if (choice == 3)
            cout<<"Length of string is: " << strObj1.Length()<<endl;
        else if(choice == 4)
        {
            int pos, len ;
            cout << "Enter position : \n";
            cin >> pos ;
            cout << "Enter length: \n";
            cin >> len ;
            if (pos>strObj1.Length()||len>strObj1.Length())
            {
                cout<<"Out of range!..\nyour string in range {0,"<<strObj1.Length()<<"}. Try again.\n";
            }
            else
            {
                cout<<"your character array: ";
                strObj1.Copy(pos,len);
                cout<<endl;
            }
        }
        else if (choice == 5)
        {
            string Temp;
            cout<<"Enter another string to swap with the first one: ";
            cin.ignore();
            getline(cin,Temp);
            MyString str2(Temp.size(),Temp);
            strObj1.Swap(str2);
            cout<<"Done..\n";
        }
        else if (choice ==6)
        {
            cout<<"Enter another string to concatenate with the first one: ";
            string s2;
            cin.ignore();
            getline(cin,s2);
            MyString stringObj2(s2.size(),s2);
            MyString TempStringObj3;
            TempStringObj3=strObj1+stringObj2;
            strObj1=TempStringObj3;
            cout << "your Concatenation: "<<TempStringObj3.Show()<<endl;
        }
        else if (choice == 7)
        {
            string s3;
            cout<<"Enter another string to compare with the first one: ";
            cin.ignore();
            getline(cin,s3);
            MyString stringObj2(s3.size(),s3);
            int checker =strObj1.Compare(stringObj2);
            if(checker==-1)
                cout<<"First string smaller than second one"<<endl;
            else if (checker==1)
                cout<<"First string greater than second one"<<endl;
            else
                cout<<"First string equal to the second one"<<endl;
        }
        else if (choice == 8)
        {
            int startIndex, endIndex ;
            cout << "Enter your start index: \n";
            cin >> startIndex ;
            cout << "Enter your end index: \n";
            cin >> endIndex ;
            if (startIndex>strObj1.Length()||endIndex>strObj1.Length())
            {
                cout<<"Out of range!..\nyour string in range {0,"<<strObj1.Length()<<"}. Try again.\n";
            }
            else
            {
                cout << "The Substring is: " ;
                strObj1.Substring(startIndex,endIndex) ;
                cout<<endl;
            }
        }
        else if (choice == 9)
        {
            cout<<"your string: ";
            strObj1.Trim();
            cout<<endl;
        }

        else if (choice == 10)
        {
            cout<<"your string: ";
            strObj1.ToLowerCase() ;
            cout<<endl;
        }

        else if (choice == 11)
        {
            cout<<"your string: ";
            strObj1.ToUpperCase() ;
            cout<<endl;
        }

        else if (choice == 12)
        {
            char ch ;
            cout << "Enter the character\n" ;
            cin >> ch ;
            string st=strObj1.Show();
            bool flag2=false;
            for (int i =Size-1; i>=0; i--)
            {
                if (st[i] == ch)
                {
                    flag2=true;
                }
            }
            if(flag2)
            {
                strObj1.IndexOf(ch) ;
                cout<<endl;
            }
            else
                cout<<"invalid character!\nyour string: "<<strObj1.Show()<<"\ntry again.\n";

        }

        else if (choice == 13)
        {
            char ch ;
            cout << "Enter the character\n" ;
            cin >> ch ;
            string st=strObj1.Show();
            bool flag2=false;
            for (int i =Size-1; i>=0; i--)
            {
                if (st[i] == ch)
                {
                    flag2=true;
                }
            }
            if(flag2)
            {
                strObj1.LastIndexOf(ch) ;
                cout<<endl;
            }
            else
                cout<<"invalid character!\nyour string: "<<strObj1.Show()<<"\ntry again.\n";

        }
        else if (choice == 14)
        {
            char oldCharacter, newCharacter;
            string st=strObj1.Show();
            bool flag2=false;
            cout << "Enter the old character: " ;
            cin >> oldCharacter ;
            for (int i =Size-1; i>=0; i--)
            {
                if (st[i] == oldCharacter)
                {
                    flag2=true;
                }
            }
            if(flag2)
            {
                cout << "Enter the new character: ";
                cin >> newCharacter ;
                cout<<"your string: ";
                strObj1.Replace(oldCharacter, newCharacter) ;
                cout<<endl;
            }
            else
                cout<<"invalid character!\nyour string: "<<strObj1.Show()<<"\ntry again.\n";

        }
        else if(choice == 15)
        {
            cout<<"your string: "<<strObj1.Show()<<endl;
        }
        else if(choice == 0)
        {
            flag=true;
        }
    }
    return 0;
}
