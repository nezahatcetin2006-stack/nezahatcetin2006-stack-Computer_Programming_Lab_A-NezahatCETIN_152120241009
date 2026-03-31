#include <iostream>

using namespace std;

struct Song{
    string title;
    string artist;
    int rating[3];
    Song* sonraki;
    Song* onceki;
};

Song* ilksarki=NULL;
Song* sonsarki=NULL;
Song* suancalinan=NULL;

void add(string t,string a,int r1,int r2,int r3){
    Song* yenisarki= new Song;
    yenisarki->title=t;
    yenisarki->artist=a;
    yenisarki->rating[0]=r1;
    yenisarki->rating[1]=r2;
    yenisarki->rating[2]=r3;
    yenisarki->sonraki= NULL;
    yenisarki->onceki= NULL;

    if (ilksarki==NULL){
        ilksarki=yenisarki;
        sonsarki=yenisarki;
        suancalinan=yenisarki;
    }else{
        sonsarki->sonraki=yenisarki;
        yenisarki->onceki=sonsarki;
        sonsarki=yenisarki;
    }
}

void next(){
    if(suancalinan->sonraki != NULL){
        suancalinan=suancalinan->sonraki;
    }else{
        cout << "son sarki" << endl;
    }
}

void prev(){
    if(suancalinan->onceki != NULL){
        suancalinan=suancalinan->onceki;
    }else{
        cout << "ilk sarki" << endl;
    }
}

void display(){
    Song* temp=ilksarki;
    while(temp!= NULL){
        if(temp==suancalinan){
            cout << "->";
        }
        cout << "Song:" << temp->title <<"_"<< temp->artist << "Ratings";
        for(int i=0;i<3;i++){
            cout << temp->rating[i] << " ";
        }
        cout << endl;
        temp = temp->sonraki;
    }
}

void sarkiyisil(){
    if (suancalinan==NULL) return;
    Song* silineceksarki=suancalinan;

    if(suancalinan->onceki!=NULL){
        suancalinan->onceki->sonraki=suancalinan->sonraki;
    }else {
        ilksarki=suancalinan->sonraki;
    }
    if(suancalinan->sonraki !=NULL){
        suancalinan->sonraki->onceki=suancalinan->onceki;
        suancalinan=suancalinan->sonraki;
    }else{
        suancalinan=suancalinan->onceki;
        sonsarki=suancalinan;
    }
    delete silineceksarki;
}


int main()
{
    add("Song 1","Artist 1",1,6,3);
    add("Song 2","Artist 2",2,4,9);
    add("Song 3","Artist 3",4,1,7);

    display();
    next();
    display();
    sarkiyisil();
    display();

    return 0;

}
