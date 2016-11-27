#include "tubes.h"

using namespace std;

void createlistgedung(listgedung &lg)
{
    lg.first=NULL;
    lg.last=NULL;
}

void createlistlantai(listlantai &ll)
{
    ll.first=NULL;
    ll.last=NULL;
}

void createlistkamar(listkamar &lk)
{
    lk.first=NULL;
    lk.last=NULL;
}

void createlistmahasiswa(listmahasiswa &lm)
{
    lm.first=NULL;
    lm.last=NULL;
}

adrgedung alokasigedung(infogedung x)
{
    adrgedung newgedung = new elmgedung;
    newgedung->info=x;
    newgedung->next=NULL;
    newgedung->prev=NULL;
    createlistlantai(newgedung->lantai);
    return newgedung;
}

adrlantai alokasilantai(infolantai x)
{
    adrlantai newlantai = new elmlantai;
    newlantai->info=x;
    newlantai->next=NULL;
    newlantai->prev=NULL;
    createlistkamar(newlantai->kamar);
    return newlantai;
}

adrkamar alokasikamar(infokamar x)
{
    adrkamar newkamar = new elmkamar;
    newkamar->info=x;
    newkamar->next=NULL;
    newkamar->prev=NULL;
    createlistmahasiswa(newkamar->mahasiswa);
    return newkamar;
}

adrmahasiswa alokasimahasiswa(infomahasiswa x)
{
    adrmahasiswa newmahasiswa = new elmmahasiswa;
    newmahasiswa->info=x;
    newmahasiswa->next=NULL;
    newmahasiswa->prev=NULL;
    return newmahasiswa;
}

bool gedung_empty(listgedung &l)
{
    return l.first == NULL;
}

bool lantai_empty(listlantai &l)
{
    return l.first == NULL;
}

bool kamar_empty(listkamar &l)
{
    return l.first == NULL;
}

bool mahasiswa_empty(listmahasiswa &l)
{
    return l.first == NULL;
}

void inputgedung(listgedung &l, adrgedung p)
{
    if(gedung_empty(l))
    {
        //TODO
        l.first=p;
        l.last=p;
    }
    else
    {
        l.last->next=p;
        p->prev=l.last;
        l.last=p;
    }
}

void inputlantai(listlantai &l, adrlantai p)
{
    if(lantai_empty(l))
    {
        //TODO
        l.first=p;
        l.last=p;
    }
    else
    {
        l.last->next=p;
        p->prev=l.last;
        l.last=p;
    }
}

void inputkamar(listkamar &l, adrkamar p)
{
    if(kamar_empty(l))
    {
        //TODO
        l.first=p;
        l.last=p;
    }
    else
    {
        l.last->next=p;
        p->prev=l.last;
        l.last=p;
    }
}

void inputmahasiswa(listmahasiswa &l, adrmahasiswa p)
{
    if(mahasiswa_empty(l))
    {
        //TODO
        l.first=p;
        l.last=p;

    }
    else
    {
        l.last->next=p;
        p->prev=l.last;
        l.last=p;
    }
}

adrgedung find_gedung(listgedung l, infogedung x)
{
    adrgedung p=l.first;
    if(!gedung_empty(l))
    {
        p = l.first;
        while(p != NULL)
        {
            if(p->info.nama == x.nama)
            {
                break;
            }
            p = p->next;
        }
    }
    return p;
}

adrlantai find_lantai(listlantai l, infolantai x)
{
    adrlantai p=l.first;
    if(!lantai_empty(l))
    {
        p = l.first;
        while(p != NULL)
        {
            if(p->info.nomorlantai == x.nomorlantai)
            {
                break;
            }
            p = p->next;
        }
    }
    return p;
}

adrkamar find_kamar(listkamar l, infokamar x)
{
    adrkamar p=l.first;
    if(!kamar_empty(l))
    {
        p = l.first;
        while(p != NULL)
        {
            if(p->info.nomorkamar == x.nomorkamar)
            {
                break;
            }
            p = p->next;
        }
    }
    return p;
}

adrmahasiswa find_mahasiswa(listmahasiswa l, infomahasiswa x)
{
    adrmahasiswa p=l.first;
    if(!mahasiswa_empty(l))
    {
        p = l.first;
        while(p != NULL)
        {
            if(p->info.namamhs == x.namamhs)
            {
                break;
            }
            p = p->next;
        }
    }
    return p;
}

void deletegedung(listgedung &l, string x)
{
    adrgedung p = l.first;
    if (p==NULL)
        cout<<"=== Data gedung Kosong ==="<<endl;
    else
    {
        adrgedung q = p;
        while (p!=NULL)
        {
            if (x==p->info.nama)
            {
                break;
            }
            else
            {
                q=p;
                p=p->next;
            }
        }
        if (p==NULL)
            cout<<"=== Data Gedung Tidak Ditemukan ===";
        else if (p == l.first)
        {
            if ((x==p->info.nama)&&(l.first->next==NULL))
            {
                l.first=NULL;
                l.last=NULL;
            }
            else
            {
                if (x==p->info.nama)
                {
                    l.first=l.first->next;
                    p->next=NULL;
                    free(p);
                }
            }
        }
        else if (p->next==NULL)
        {
            q->next=NULL;
            p->prev=NULL;
            l.last=q;
        }
        else
        {
            q->next=p->next;
            p->next=NULL;
            p->next->prev=q;
            p->prev=NULL;
        }
        free(p);
    }
}

void deletelantai(listlantai &l, int x)
{
    adrlantai p = l.first;
    if (p==NULL)
        cout<<"=== Data Lantai Kosong ==="<<endl;
    else
    {
        adrlantai q = p;
        while (p!=NULL)
        {
            if (x==p->info.nomorlantai)
            {
                break;
            }
            else
            {
                q=p;
                p=p->next;
            }
        }
        if (p==NULL)
            cout<<"=== Data Lantai Tidak Ditemukan ===";
        else if (p == l.first)
        {
            if ((x==p->info.nomorlantai)&&(l.first->next==NULL))
            {
                l.first=NULL;
                l.last=NULL;
            }
            else
            {
                if (x==p->info.nomorlantai)
                {
                    l.first=l.first->next;
                    p->next=NULL;
                    free(p);
                }
            }
        }
        else if (p->next==NULL)
        {
            q->next=NULL;
            p->prev=NULL;
            l.last=q;
        }
        else
        {
            q->next=p->next;
            p->next=NULL;
            p->next->prev=q;
            p->prev=NULL;
        }
        free(p);
    }
}

void deletekamar(listkamar &l, int x)
{
    adrkamar p = l.first;
    if (p==NULL)
        cout<<"=== Data Kamar Kosong ==="<<endl;
    else
    {
        adrkamar q = p;
        while (p!=NULL)
        {
            if (x==p->info.nomorkamar)
            {
                break;
            }
            else
            {
                q=p;
                p=p->next;
            }
        }
        if (p==NULL)
            cout<<"=== Data Kamar Tidak Ditemukan ===";
        else if (p == l.first)
        {
            if ((x==p->info.nomorkamar)&&(l.first->next==NULL))
            {
                l.first=NULL;
                l.last=NULL;
            }
            else
            {
                if (x==p->info.nomorkamar)
                {
                    l.first=l.first->next;
                    p->next=NULL;
                    free(p);
                }
            }
        }
        else if (p->next==NULL)
        {
            q->next=NULL;
            p->prev=NULL;
            l.last=q;
        }
        else
        {
            q->next=p->next;
            p->next=NULL;
            p->next->prev=q;
            p->prev=NULL;
        }
        free(p);
    }
}

void deletemahasiswa(listmahasiswa &l, string x)
{
    adrmahasiswa p = l.first;
    if (p==NULL)
        cout<<"=== Data Mahasiswa Kosong ==="<<endl;
    else
    {
        adrmahasiswa q = p;
        while (p!=NULL)
        {
            if (x==p->info.nim)
            {
                break;
            }
            else
            {
                q=p;
                p=p->next;
            }
        }
        if (p==NULL)
            cout<<"=== Data Mahasiswa Tidak Ditemukan ===";
        else if (p == l.first)
        {
            if ((x==p->info.nim)&&(l.first->next==NULL))
            {
                l.first=NULL;
                l.last=NULL;
            }
            else
            {
                if (x==p->info.nim)
                {
                    l.first=l.first->next;
                    p->next=NULL;
                    free(p);
                }
            }
        }
        else if (p->next==NULL)
        {
            q->next=NULL;
            p->prev=NULL;
            l.last=q;
        }
        else
        {
            q->next=p->next;
            p->next=NULL;
            p->next->prev=q;
            p->prev=NULL;
        }
        free(p);
    }
}

void editgedung(listgedung &l, adrgedung p)
{
    adrgedung q;
    system("cls");
    cout<<"#================================#"<<endl;
    cout<<"#          Update Gedung         #"<<endl;
    cout<<"#================================#"<<endl;
    cout<<" Masukan data gedung baru"<<endl;
    infogedung x;
    cout<<" Nama Gedung : ";
    cin>>x.nama;
    q=find_gedung(l,x);
    if (q==NULL)
    {
        (p)->info=x;
        cout<<"=== update gedung sukses ==="<<endl;
        cout<<"=== tekan 0 untuk kembali ==="<<endl;
    }
    else
    {
        cout<<"=== nama gedung sudaha ada ==="<<endl;
        cout<<"=== tekan 0 untuk kembali ==="<<endl;
    }
}

void editlantai(listlantai &l, adrlantai p)
{
    adrlantai q;
    system("cls");
    cout<<"#================================#"<<endl;
    cout<<"#          Update Lantai         #"<<endl;
    cout<<"#================================#"<<endl;
    cout<<" Masukan data lantai baru"<<endl;
    infolantai x;
    cout<<" Nomor Lantai : ";
    cin>>x.nomorlantai;
    q=find_lantai(l,x);
    if (q==NULL)
    {
        (p)->info=x;
        cout<<"=== update lantai sukses  ==="<<endl;
        cout<<"=== tekan 0 untuk kembali ==="<<endl;
    }
    else
    {
        cout<<"=== nomor lantai sudah ada ==="<<endl;
        cout<<"=== tekan 0 untuk kembali  ==="<<endl;
    }
}

void editkamar(listkamar &l, adrkamar p)
{
    adrkamar q;
    system("cls");
    cout<<"#================================#"<<endl;
    cout<<"#          Update Kamar          #"<<endl;
    cout<<"#================================#"<<endl;
    cout<<" Masukan data Kamar baru"<<endl;
    infokamar x;
    cout<<" Nomor Kamar : ";
    cin>>x.nomorkamar;
    q=find_kamar(l,x);
    if (q==NULL)
    {
        (p)->info=x;
        cout<<"=== update kamar sukses ==="<<endl;
        cout<<"=== tekan 0 untuk kembali  ==="<<endl;
    }
    else
    {
        cout<<"=== nomor kamar sudah ada ==="<<endl;
        cout<<"=== tekan 0 untuk kembali  ==="<<endl;
    }
}

void editmahasiswa(listmahasiswa &l, adrmahasiswa p)
{
    char input[100];
    adrmahasiswa q;
    system("cls");
    cout<<"#================================#"<<endl;
    cout<<"#        Update Mahasiswa        #"<<endl;
    cout<<"#================================#"<<endl;
    cout<<" Masukan data Mahasiswa baru"<<endl;
    infomahasiswa x;
    cout<<" NIM Mahasiswa : ";
    cin>>x.nim;
    cout<<" Nama Mahasiswa : ";
    cin.ignore();
    cin.getline(input,100);
    x.namamhs=input;
    cout<<" Jurusan Mahasiswa : ";
    cin>>x.jurusan;
    q=find_mahasiswa(l,x);
    if (q==NULL)
    {
        (p)->info=x;
        cout<<"=== update mahasiswa sukses  ==="<<endl;
        cout<<"=== tekan 0 untuk kembali ==="<<endl;
    }
    else
    {
        cout<<"=== NIM mahasiswa sudah ada  ==="<<endl;
        cout<<"=== tekan 0 untuk kembali ==="<<endl;
    }
}

adrmahasiswa searchmahsiswa(string x, listgedung h)
{
    adrgedung a;
    adrlantai b;
    adrkamar c;
    adrmahasiswa s;
    adrmahasiswa mhs=NULL;
    adrgedung p=h.first;
    while(p!=NULL)
    {

        adrlantai q = (p)->lantai.first;
        while (q!=NULL)
        {

            adrkamar r = (q)->kamar.first;
            while (r!=NULL)
            {

                s  = (r)->mahasiswa.first;
                while (s!=NULL)
                {
                    if (s->info.nim==x)
                    {
                        mhs=s;
                        a=p;
                        b=q;
                        c=r;
                    }
                    s = (s)->next;
                }
                r = (r)->next;
            }
            q = (q)->next;
        }
        p = (p)->next;
    }
    if (mhs!=NULL)
    {
        system("cls");
        cout<<"#================================#"<<endl;
        cout<<"#    0.  Kembali                 #"<<endl;
        cout<<"#================================#"<<endl;
        cout<<"#         Info Mahasiswa         #"<<endl;
        cout<<"#================================#"<<endl;
        cout<<" Nama Mahasiswa    : "<<mhs->info.namamhs<<endl;
        cout<<" Jurusan Mahasiswa : "<<mhs->info.jurusan<<endl;
        cout<<" Nama Gedung       : "<<a->info.nama<<endl;
        cout<<" Nomor Lantai      : "<<b->info.nomorlantai<<endl;
        cout<<" Nomor Kamar       : "<<c->info.nomorkamar<<endl;

    }
    else
    {
        cout<<endl;
        cout<<"=== nim mahasiswa tidak ditemukan ==="<<endl;
        cout<<"===    tekan 0 untuk kembali    ==="<<endl;
    }
}

void viewall(listgedung h, listlantai i, listkamar j, listmahasiswa k)
{
    int x;
    adrgedung p = ((h).first);
    int a,b=1,c;
    char n;

    system("cls");
    cout<<"#================================#"<<endl;
    cout<<"#   0.  Kembali                  #"<<endl;
    cout<<"#================================#"<<endl;
    cout<<"#          SEMUA DATA            #"<<endl;
    cout<<"#================================#"<<endl;
    cout<<endl;
    cout<<"================================================="<<endl;
    while(p!=NULL)
    {
        cout<<"                 Data Gedung | "<<(p)->info.nama<<" | "<<endl;
        cout<<"-------------------------------------------------"<<endl;
        adrlantai q = (p)->lantai.first;
        while (q!=NULL)
        {
            cout<<" Lantai - "<<(q)->info.nomorlantai<<endl;
            cout<<"-------------------------------------------------"<<endl;
            adrkamar r = (q)->kamar.first;
            while (r!=NULL)
            {
                cout<<" Kamar - "<<(r)->info.nomorkamar<<endl;
                cout<<"   Jumlah Penghuni : "<<(r)->info.jumlahpenghuni<<endl;
                cout<<"   Status          : "<<(r)->info.status<<endl;
                cout<<"   Data Penghuni   : "<<endl;
                cout<<endl;
                adrmahasiswa s = (r)->mahasiswa.first;
                c=0;
                while (s!=NULL)
                {
                    c+=1;
                    cout<<"     NIM Mahasiswa-"<<c<<"     : "<<(s)->info.nim<<endl;
                    cout<<"     Nama Mahasiswa-"<<c<<"    : "<<(s)->info.namamhs<<endl;
                    cout<<"     Jurusan Mahasiswa-"<<c<<" : "<<(s)->info.jurusan<<endl;
                    cout<<endl;
                    s = (s)->next;
                }
                cout<<"-------------------------------------------------"<<endl;
                cout<<endl;

                r = (r)->next;
            }
            q = (q)->next;
        }
        p = (p)->next;
        cout<<"================================================="<<endl;
    }
}

void viewkmrksg(listgedung h, listlantai i, listkamar j, listmahasiswa k)
{
    int x;
    adrgedung p = ((h).first);
    int a,b=1,c=0;
    char n;

    system("cls");
    cout<<"#================================#"<<endl;
    cout<<"#   0.  Kembali                  #"<<endl;
    cout<<"#================================#"<<endl;
    cout<<"#          KAMAR KOSONG          #"<<endl;
    cout<<"#================================#"<<endl;
    cout<<endl;
    cout<<"================================================="<<endl;
    while(p!=NULL)
    {
        cout<<" |Nama Gedung                     : "<<(p)->info.nama<<endl;
        adrlantai q = (p)->lantai.first;
        while (q!=NULL)
        {
            cout<<" |   |Nomor lantai                : "<<(q)->info.nomorlantai<<endl;
            adrkamar r = (q)->kamar.first;
            while (r!=NULL)
            {
                if(r->info.jumlahpenghuni==0)
                {
                    c=1;
                    cout<<" |   |   |Nomor kamar             : "<<(r)->info.nomorkamar<<endl;
                }
                if((r->next==NULL)&&(c==0))
                {
                    cout<<" |   |   |Tidak Ada Kamar Kosong"<<endl;
                }
                r = (r)->next;
            }
            q = (q)->next;
        }
        p = (p)->next;
        cout<<"================================================="<<endl;
    }
}

void viewkmrpnh(listgedung h, listlantai i, listkamar j, listmahasiswa k)
{
    int x;
    adrgedung p = ((h).first);
    int a,b=1,c=0;
    char n;

    system("cls");
    cout<<"#================================#"<<endl;
    cout<<"#   0.  Kembali                  #"<<endl;
    cout<<"#================================#"<<endl;
    cout<<"#          KAMAR PENUH           #"<<endl;
    cout<<"#================================#"<<endl;
    cout<<endl;
    cout<<"================================================="<<endl;
    while(p!=NULL)
    {
        cout<<" |Nama Gedung                     : "<<(p)->info.nama<<endl;
        adrlantai q = (p)->lantai.first;
        while (q!=NULL)
        {
            cout<<" |   |Nomor lantai                : "<<(q)->info.nomorlantai<<endl;
            adrkamar r = (q)->kamar.first;
            while (r!=NULL)
            {
                if(r->info.jumlahpenghuni==4)
                {
                    c=1;
                    cout<<" |   |   |Nomor kamar             : "<<(r)->info.nomorkamar<<endl;
                }
                if((r->next==NULL)&&(c==0))
                {
                    cout<<" |   |   |Tidak Ada Kamar Penuh"<<endl;
                }
                r = (r)->next;
            }
            q = (q)->next;
        }
        p = (p)->next;
        cout<<"================================================="<<endl;
    }
}

void viewkmrisi(listgedung h, listlantai i, listkamar j, listmahasiswa k)
{
    int x;
    adrgedung p = ((h).first);
    int a,b=1,c=0;
    char n;

    system("cls");
    cout<<"#================================#"<<endl;
    cout<<"#   0.  Kembali                  #"<<endl;
    cout<<"#================================#"<<endl;
    cout<<"#       KAMAR BISA DIISI         #"<<endl;
    cout<<"#================================#"<<endl;
    cout<<endl;
    cout<<"================================================="<<endl;
    while(p!=NULL)
    {
        cout<<" |Nama Gedung                     : "<<(p)->info.nama<<endl;
        adrlantai q = (p)->lantai.first;
        while (q!=NULL)
        {
            cout<<" |   |Nomor lantai                : "<<(q)->info.nomorlantai<<endl;
            adrkamar r = (q)->kamar.first;
            while (r!=NULL)
            {
                if(r->info.jumlahpenghuni<4)
                {
                    c=1;
                    cout<<" |   |   |Nomor kamar             : "<<(r)->info.nomorkamar<<endl;
                }
                if((r->next==NULL)&&(c==0))
                {
                    cout<<" |   |   |Tidak Ada Kamar Yang Bisa Diisi"<<endl;
                }
                r = (r)->next;
            }
            q = (q)->next;
        }
        p = (p)->next;
        cout<<"================================================="<<endl;
    }
}

void pindahmhs(adrmahasiswa s,listgedung lg, listlantai ll, listkamar lk, listmahasiswa lm)
{
    adrmahasiswa mhs;
    adrgedung p;
    adrkamar r;
    adrlantai q;
    infogedung ig;
    infogedung yu;
    infokamar ik;
    infolantai il;
    infomahasiswa im;
    system("cls");
    cout<<"#================================#"<<endl;
    cout<<"#       Pindah Mahasiswa         #"<<endl;
    cout<<"#================================#"<<endl;
    cout<<" Masukkan Nama Gedung Tujuan: ";
    cin>>ig.nama;
    p = find_gedung(lg,ig);
    if (p==NULL)
    {
        cout<<"=== nama gedung tidak ditemukan ==="<<endl;
        cout<<"===     tekan 0 untuk kembali    ==="<<endl;
    }
    else
    {
        cout<<" Nomor Lantai Tujuan: ";
        cin>>il.nomorlantai;
        q = find_lantai(p->lantai,il);
        if (q==NULL)
        {
            cout<<"=== nomor lantai tidak ditemukan ==="<<endl;
            cout<<"===    tekan 0 untuk kembali    ==="<<endl;
        }
        else
        {
            cout<<" Nomor Kamar Tujuan: ";
            cin>>ik.nomorkamar;
            r = find_kamar(q->kamar,ik);
            if (r==NULL)
            {
                cout<<"=== nomor kamar tidak ditemukan ==="<<endl;
                cout<<"===      tekan 0 untuk kembali    ==="<<endl;
            }
            else if(r->info.status=="penuh")
            {
                cout<<"=== jumlah penghuni kamar sudah penuh ==="<<endl;
                cout<<"===      tekan 0 untuk kembali    ==="<<endl;
            }
            else
            {

                mhs=find_mahasiswa(lm,s->info);
                if (mhs==NULL)
                {
                    inputmahasiswa(r->mahasiswa,s);
                    cout<<"=== input Mahasiswa baru sukses ==="<<endl;
                    cout<<"===  tekan 0 untuk kembali   ==="<<endl;
                }
                else
                {
                    cout<<"=== NIM Mahasiswa Sudah ada ==="<<endl;
                    cout<<"===  tekan 0 untuk kembali   ==="<<endl;
                }
            }
        }
    }
}

int menuView (listgedung h, listlantai i, listkamar j, listmahasiswa k)
{
    int a,b=1;
    char n;
    while (b==1)
    {
        system("cls");
        cout<<"#================================#"<<endl;
        cout<<"#   0.  Kembali                  #"<<endl;
        cout<<"#================================#"<<endl;
        cout<<"#          LIHAT DATA            #"<<endl;
        cout<<"#================================#"<<endl;
        cout<<"#   1.  Lihat Kamar Penuh        #"<<endl;
        cout<<"#   2.  Lihat Kamar Kosong       #"<<endl;
        cout<<"#   3.  Lihat Kamar Bisa Diisi   #"<<endl;
        cout<<"#   4.  Lihat semua data         #"<<endl;
        cout<<"#================================#"<<endl;
        cout<<" Masukkan pilihan    : ";
        cin>>a;
        switch (a)
        {
        case 1:
            viewkmrpnh(h,i,j,k);
            cin>>n;
            break;
        case 2:
            viewkmrksg(h,i,j,k);
            cin>>n;
            break;
        case 3:
            viewkmrisi(h,i,j,k);
            cin>>n;
            break;
        case 4:
            viewall(h,i,j,k);
            cin>>n;
            break;
        case 0:
            b=2;
            break;
        default :
            system("cls");
            cout<<"=== pilihan tidak tersedia dalam menu ==="<<endl;
            cout<<"    ===   tekan 0 untuk kembali   ===    "<<endl;
            cin>>n;
            break;
        }
    }
}
