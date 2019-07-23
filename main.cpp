#include <iostream>
using namespace std;
class song{
private:
    int length;
    char* artist;
    char* jenre;
public:
    song(){
        length=0;
        artist= new char[1];
        artist[0]='\0';
        jenre= new char[1];
        jenre[0]='\0';
    }
    song(int _length, char* _artist, char* _jenre){
        length=_length;
        int sizee=0;
        for(int i=0; _artist[i]!='\0'; i++){
            sizee++;
        }
        artist=new char[sizee];
        for(int i=0; i<sizee; i++){
            artist[i]=_artist[i];
        }
        sizee=0;
        for(int i=0; _jenre[i]!='\0'; i++){
            sizee++;
        }
        jenre=new char[sizee];
        for(int i=0; i<sizee; i++){
            jenre[i]=_jenre[i];
        }
    }
    song(song& other){
        length=other.length;

        int sizee=0;
        for(int i=0; other.artist[i]!='\0'; i++){
            sizee++;
        }
        artist=new char[sizee];
        for(int i=0; i<sizee; i++){
            artist[i]=other.artist[i];
        }
        sizee=0;
        for(int i=0; other.jenre[i]!='\0'; i++){
            sizee++;
        }
        jenre=new char[sizee];
        for(int i=0; i<sizee; i++){
            jenre[i]=other.jenre[i];
        }

    }
    song& operator=(song& other){
        if(this != &other){
            delete[] artist;
            delete[] jenre;
            length=other.length;
            int sizee=0;
            for(int i=0; other.artist[i]!='\0'; i++){
                sizee++;
            }
            artist=new char[sizee];
            for(int i=0; i<sizee; i++){
                artist[i]=other.artist[i];
            }
            sizee=0;
            for(int i=0; other.jenre[i]!='\0'; i++){
                sizee++;
            }
            jenre=new char[sizee];
            for(int i=0; i<sizee; i++){
                jenre[i]=other.jenre[i];
            }

        }
        return *this;
    }

    void printsong(){
        cout<<"Length: "<<length<<" minutes"<<endl;
        cout<<"Artist: "<<artist<<endl;
        cout<<"Jenre: "<<jenre<<endl;
    }
    ~song(){
        delete[] artist;
        delete[] jenre;
    }
};
class playlist{
private:
    song* lista;
    int sizee;
    int capacity;
public:
    playlist(){
        sizee=0;
        capacity=4;
        lista= new song[capacity];
    }
    void resizee(){
        capacity=capacity*2;
        song* newlista;
        newlista= new song[capacity];
        for(int i=0; i<sizee; i++){
            newlista[i]=lista[i];
        }
        delete [] lista;
        lista=newlista;

    }
    void add(song added){
        if(sizee+1>capacity){resizee();}
        lista[sizee]=added;
        sizee++;
    }
    void printplaylist(){
        cout<<sizee;
        for(int i=0; i<sizee; i++){
            lista[i].printsong();
            cout<<endl;
        }
    }
};

int main(){
    song habibi(2,"azis","mazno");
    song hab(habibi);
    song ha;
    song h;
    ha=hab;
    //ha.printsong();
    playlist p1;
    p1.add(habibi);
    p1.add(hab);
    p1.add(h);
    p1.add(habibi);
    p1.add(hab);
    p1.add(h);
    p1.add(habibi);
    p1.add(hab);
    p1.add(h);
    p1.add(habibi);
    p1.add(hab);
    p1.add(h);p1.add(habibi);
    p1.add(hab);
    p1.add(h);
    p1.add(habibi);
    p1.add(hab);
    p1.add(h);p1.add(habibi);
    p1.add(hab);
    p1.add(h);
    p1.add(habibi);
    p1.add(hab);
    p1.add(h);
    p1.printplaylist();

    return 0;
}
