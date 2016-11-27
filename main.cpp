#include <iostream>
#include "tubes.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

using namespace std;
void gotoxy(int x, int y)
{
    printf("\033[%d;%df", y, x);
    fflush(stdout);
}


int main()
{
    listgedung lg;
    char input[100];
    listkamar lk;
    listlantai ll;
    listmahasiswa lm;
    createlistgedung(lg);
    createlistkamar(lk);
    createlistlantai(ll);
    createlistmahasiswa(lm);
    adrgedung p;
    //adrgedung a;
    adrkamar r;
    adrlantai q;
    adrmahasiswa s;
    infogedung ig;
    infogedung yu;
    infokamar ik;
    infolantai il;
    infomahasiswa im;
    /*ig.nama='a';
    ik.nomorkamar=1;
    il.nomorlantai=1;
    im.namamhs="graham";
    yu.nama='b';
    a=alokasigedung(yu);
    p=alokasigedung(ig);
    q=alokasikamar(ik);
    r=alokasilantai(il);
    s=alokasimahasiswa(im);
    inputgedung(lg,p);
    inputgedung(lg,a);
    inputlantai(p->lantai,r);
    inputkamar(r->kamar,q);
    inputmahasiswa(q->mahasiswa,s);
    view(lg,ll,lk,lm);*/
    ig.nama='a';
    p=alokasigedung(ig);
    inputgedung(lg,p);
    il.nomorlantai=1;
    q=alokasilantai(il);
    inputlantai(p->lantai,q);
    ik.nomorkamar=1;
    ik.jumlahpenghuni=1;
    ik.status="bisa diisi";
    r=alokasikamar(ik);
    inputkamar(q->kamar,r);
    im.nim="1301141264";
    im.namamhs="Graham";
    im.jurusan="IF";
    s=alokasimahasiswa(im);
    inputmahasiswa(r->mahasiswa,s);
    ig.nama='b';
    p=alokasigedung(ig);
    inputgedung(lg,p);
    il.nomorlantai=1;
    q=alokasilantai(il);
    inputlantai(p->lantai,q);
    ik.nomorkamar=1;
    ik.jumlahpenghuni=0;
    ik.status="kosong";
    r=alokasikamar(ik);
    inputkamar(q->kamar,r);

    int a,d,b=1,c=1,ch;
    char n;
    while (b==1)
    {
        system("cls");
        cout<<"       ######  ####    ###   "<<endl;
        cout<<"      ##    ##  ##    ## ##  "<<endl;
        cout<<"      ##        ##   ##   ## "<<endl;
        cout<<"       ######   ##  ##     ##"<<endl;
        cout<<"            ##  ##  #########"<<endl;
        cout<<"      ##    ##  ##  ##     ##"<<endl;
        cout<<"       ######  #### ##     ##"<<endl;
        cout<<"      Sistem Informasi Asrama  "<<endl;
        cout<<"#================================#"<<endl;
        cout<<"#           MENU UTAMA           #"<<endl;
        cout<<"#================================#"<<endl;
        cout<<"#    1.  Input Data              #"<<endl;
        cout<<"#    2.  Hapus Data              #"<<endl;
        cout<<"#    3.  Update Data             #"<<endl;
        cout<<"#    4.  Lihat Data              #"<<endl;
        cout<<"#    5.  Cari Mahasiswa          #"<<endl;
        cout<<"#================================#"<<endl;
        cout<<"#    0.  Exit                    #"<<endl;
        cout<<"#================================#"<<endl;
        cout<<" Masukkan pilihan    : ";
        cin>>a;
        switch (a)
        {
        case 1:
            while (c==1)
            {
                system("cls");
                cout<<"#================================#"<<endl;
                cout<<"#    0.  Kembali                 #"<<endl;
                cout<<"#================================#"<<endl;
                cout<<"#           INPUT DATA           #"<<endl;
                cout<<"#================================#"<<endl;
                cout<<"#    1.  Input Gedung            #"<<endl;
                cout<<"#    2.  Input Lantai            #"<<endl;
                cout<<"#    3.  Input Kamar             #"<<endl;
                cout<<"#    4.  Input Mahasiswa         #"<<endl;
                cout<<"#================================#"<<endl;
                cout<<" Masukkan pilihan    : ";
                cin>>d;
                switch (d)
                {
                case 1:
                    system("cls");
                    cout<<"#================================#"<<endl;
                    cout<<"#          Input Gedung          #"<<endl;
                    cout<<"#================================#"<<endl;
                    cout<<" Nama Gedung : ";
                    cin>>ig.nama;
                    if (find_gedung(lg,ig)==NULL)
                    {
                        p=alokasigedung(ig);
                        inputgedung(lg,p);
                        cout<<endl;
                        cout<<"=== input Gedung baru sukses ==="<<endl;
                        cout<<"===   tekan 0 untuk kembali   ==="<<endl;
                    }
                    else
                    {
                        cout<<endl;
                        cout<<"=== nama gedung sudah ada ==="<<endl;
                        cout<<"===   tekan 0 untuk kembali   ==="<<endl;
                    }
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                case 2:
                    system("cls");
                    cout<<"#================================#"<<endl;
                    cout<<"#          Input Lantai          #"<<endl;
                    cout<<"#================================#"<<endl;
                    cout<<" Masukkan Nama Gedung : ";
                    cin>>ig.nama;
                    p = find_gedung(lg,ig);
                    if (p==NULL)
                    {
                        cout<<"=== nama gedung tidak ditemukan ==="<<endl;
                        cout<<"===     tekan 0 untuk kembali    ==="<<endl;
                    }
                    else
                    {
                        system("cls");
                        cout<<"#================================#"<<endl;
                        cout<<"#          Input Lantai          #"<<endl;
                        cout<<"#================================#"<<endl;
                        cout<<" Nomor Lantai  : ";
                        cin>>il.nomorlantai;
                        if (find_lantai(ll,il)==NULL)
                        {
                            q=alokasilantai(il);
                            inputlantai(p->lantai,q);
                            cout<<endl;
                            cout<<"=== input lantai baru sukses ==="<<endl;
                            cout<<"===  tekan 0 untuk kembali   ==="<<endl;
                        }
                        else
                        {
                            cout<<endl;
                            cout<<"=== nomor lantai sudah ada ==="<<endl;
                            cout<<"===  tekan 0 untuk kembali   ==="<<endl;
                        }
                    }
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                case 3:
                    system("cls");
                    cout<<"#================================#"<<endl;
                    cout<<"#         Input Kamar            #"<<endl;
                    cout<<"#================================#"<<endl;
                    cout<<" Masukkan Nama Gedung : ";
                    cin>>ig.nama;
                    p = find_gedung(lg,ig);
                    if (p==NULL)
                    {
                        cout<<"=== nama gedung tidak ditemukan ==="<<endl;
                        cout<<"===     tekan 0 untuk kembali    ==="<<endl;
                    }
                    else
                    {
                        cout<<" Masukkan Nomor Lantai  : ";
                        cin>>il.nomorlantai;
                        q = find_lantai(p->lantai,il);
                        if (q==NULL)
                        {
                            cout<<"=== nomor lantai tidak ditemukan ==="<<endl;
                            cout<<"===    tekan 0 untuk kembali    ==="<<endl;
                        }
                        else
                        {
                            system("cls");
                            cout<<"#================================#"<<endl;
                            cout<<"#         Input Kamar            #"<<endl;
                            cout<<"#================================#"<<endl;
                            cout<<" Masukkan Nomor Kamar : ";
                            cin>>ik.nomorkamar;
                            ik.jumlahpenghuni=0;
                            ik.status="kosong";
                            if (find_kamar(lk,ik)==NULL)
                            {
                                r=alokasikamar(ik);
                                inputkamar(q->kamar,r);
                                cout<<endl;
                                cout<<"=== input Kamar baru sukses ==="<<endl;
                                cout<<"===    tekan 0 untuk kembali   ==="<<endl;
                            }
                            else
                            {
                                cout<<endl;
                                cout<<"=== nomor kamar sudah ada ==="<<endl;
                                cout<<"===    tekan 0 untuk kembali   ==="<<endl;
                            }
                        }
                    }
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                case 4:
                    system("cls");
                    cout<<"#================================#"<<endl;
                    cout<<"#          Input Mahasiswa       #"<<endl;
                    cout<<"#================================#"<<endl;
                    cout<<" Masukkan Nama Gedung : ";
                    cin>>ig.nama;
                    p = find_gedung(lg,ig);
                    if (p==NULL)
                    {
                        cout<<"=== nama gedung tidak ditemukan ==="<<endl;
                        cout<<"===     tekan 0 untuk kembali    ==="<<endl;
                    }
                    else
                    {
                        cout<<" Masukkan Nama Lantai  : ";
                        cin>>il.nomorlantai;
                        q = find_lantai(p->lantai,il);
                        if (q==NULL)
                        {
                            cout<<"=== nama lantai tidak ditemukan ==="<<endl;
                            cout<<"===    tekan 0 untuk kembali    ==="<<endl;
                        }
                        else
                        {
                            cout<<" Masukkan Nomor Kamar : ";
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
                                system("cls");
                                cout<<"#================================#"<<endl;
                                cout<<"#          Input Mahasiswa       #"<<endl;
                                cout<<"#================================#"<<endl;
                                cout<<" NIM Mahasiswa : ";
                                cin>>im.nim;
                                cout<<" Nama Mahasiswa        : ";
                                cin.ignore();
                                cin.getline(input,100);
                                im.namamhs=input;
                                cout<<" Jurusan : ";
                                cin>>im.jurusan;
                                if(r->info.jumlahpenghuni!=4)
                                    r->info.jumlahpenghuni+=1;
                                if(r->info.jumlahpenghuni==4)
                                    r->info.status="penuh";
                                else
                                    r->info.status="bisa diisi";
                                if (find_mahasiswa(lm,im)==NULL)
                                {
                                    s=alokasimahasiswa(im);
                                    inputmahasiswa(r->mahasiswa,s);
                                    cout<<endl;
                                    cout<<"=== input Mahasiswa baru sukses ==="<<endl;
                                    cout<<"===  tekan 0 untuk kembali   ==="<<endl;
                                }
                                else
                                {
                                    cout<<endl;
                                    cout<<"=== NIM mahasiswa sudah ada ==="<<endl;
                                    cout<<"===  tekan 0 untuk kembali   ==="<<endl;
                                }
                            }
                        }
                    }
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                case 0:
                    c=2;
                    break;
                default :
                    system("cls");
                    cout<<"=== pilihan tidak tersedia dalam menu ==="<<endl;
                    cout<<"=======   tekan 0 untuk kembali   ======="<<endl;
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                }
            }
            c=1;
            break;
        case 2:
            while (c==1)
            {
                system("cls");
                cout<<"#================================#"<<endl;
                cout<<"#    0.  Kembali                 #"<<endl;
                cout<<"#================================#"<<endl;
                cout<<"#           HAPUS DATA           #"<<endl;
                cout<<"#================================#"<<endl;
                cout<<"#    1.  Hapus Gedung            #"<<endl;
                cout<<"#    2.  Hapus Lantai            #"<<endl;
                cout<<"#    3.  Hapus Kamar             #"<<endl;
                cout<<"#    4.  Hapus Mahasiswa         #"<<endl;
                cout<<"#================================#"<<endl;
                cout<<" Masukkan pilihan    : ";
                cin>>d;
                switch (d)
                {
                case 1:
                    system("cls");
                    cout<<"#================================#"<<endl;
                    cout<<"#         Hapus Gedung           #"<<endl;
                    cout<<"#================================#"<<endl;
                    cout<<" Masukan nama gedung yang ingin dihapus"<<endl;
                    cout<<" Nama gedung: ";
                    cin>>ig.nama;
                    deletegedung(lg,ig.nama);
                    cout<<"=== data gedung "<<ig.nama<<" telah dihapus ==="<<endl;
                    cout<<"============   tekan 0 untuk kembali   ============="<<endl;
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                case 2:
                    system("cls");
                    cout<<"#================================#"<<endl;
                    cout<<"#         Hapus Lantai           #"<<endl;
                    cout<<"#================================#"<<endl;
                    cout<<" Masukkan Nama Gedung: ";
                    cin>>ig.nama;
                    p = find_gedung(lg,ig);
                    if (p==NULL)
                    {
                        cout<<"=== nama gedung tidak ditemukan ==="<<endl;
                        cout<<"===     tekan 0 untuk kembali    ==="<<endl;
                    }
                    else
                    {
                        cout<<" Masukan nomor lantai yang ingin dihapus"<<endl;
                        cout<<" Nomor Lantai: ";
                        cin>>il.nomorlantai;
                        deletelantai(ll,il.nomorlantai);
                        cout<<"=== data lantai "<<il.nomorlantai<<" telah dihapus ==="<<endl;
                        cout<<"         ===   tekan 0 untuk kembali   ===        "<<endl;
                    };
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                case 3:
                    system("cls");
                    cout<<"#================================#"<<endl;
                    cout<<"#        Hapus Kamar             #"<<endl;
                    cout<<"#================================#"<<endl;
                    cout<<" Masukkan Nama Gedung: ";
                    cin>>ig.nama;
                    p = find_gedung(lg,ig);
                    if (p==NULL)
                    {
                        cout<<"=== nama gedung tidak ditemukan ==="<<endl;
                        cout<<"===     tekan 0 untuk kembali    ==="<<endl;
                    }
                    else
                    {
                        cout<<" Nomor Lantai: ";
                        cin>>il.nomorlantai;
                        q = find_lantai(p->lantai,il);
                        if (q==NULL)
                        {
                            cout<<"=== nomor lantai tidak ditemukan ==="<<endl;
                            cout<<"===    tekan 0 untuk kembali    ==="<<endl;
                        }
                        else
                        {
                            cout<<" Masukan nomor kamar yang ingin dihapus"<<endl;
                            cout<<" Nomor Kamar: ";
                            cin>>ik.nomorkamar;
                            deletekamar(q->kamar,ik.nomorkamar);
                            cout<<"=== data kamar "<<ik.nomorkamar<<" telah dihapus ==="<<endl;
                            cout<<"           ===   tekan 0 untuk kembali   ===          "<<endl;
                        }
                    };
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                case 4:
                    system("cls");
                    cout<<"#================================#"<<endl;
                    cout<<"#         Hapus Mahasiswa        #"<<endl;
                    cout<<"#================================#"<<endl;
                    cout<<" Masukkan Nama Gedung: ";
                    cin>>ig.nama;
                    p = find_gedung(lg,ig);
                    if (p==NULL)
                    {
                        cout<<"=== nama gedung tidak ditemukan ==="<<endl;
                        cout<<"===     tekan 0 untuk kembali    ==="<<endl;
                    }
                    else
                    {
                        cout<<" Nomor Lantai: ";
                        cin>>il.nomorlantai;
                        q = find_lantai(p->lantai,il);
                        if (q==NULL)
                        {
                            cout<<"=== nomor lantai tidak ditemukan ==="<<endl;
                            cout<<"===    tekan 0 untuk kembali    ==="<<endl;
                        }
                        else
                        {
                            cout<<" Nomor Kamar: ";
                            cin>>ik.nomorkamar;
                            r = find_kamar(q->kamar,ik);
                            if (r==NULL)
                            {
                                cout<<"=== nomor kamar tidak ditemukan ==="<<endl;
                                cout<<"===      tekan 0 untuk kembali    ==="<<endl;
                            }
                            else
                            {
                                cout<<" Masukan nim mahasiswa yang ingin dihapus"<<endl;
                                cout<<" Nim Mahasiswa  : ";
                                cin>>im.nim;
                                deletemahasiswa(r->mahasiswa,im.nim);

                                r->info.jumlahpenghuni-=1;
                                if(r->info.jumlahpenghuni==0)
                                    r->info.status="kosong";
                                else
                                    r->info.status="masih bisa diisi";
                                cout<<"=== data Mahasiswa "<<im.nim<<" telah dihapus ==="<<endl;
                                cout<<"         ===   tekan 0 untuk kembali   ===        "<<endl;

                            }
                        }
                    };
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                case 0:
                    c=2;
                    break;
                default :
                    system("cls");
                    cout<<"=== pilihan tidak tersedia dalam menu ==="<<endl;
                    cout<<"    ===   tekan 0 untuk kembali   ===    "<<endl;
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                }
            }
            c=1;
            break;
        case 3:
            while (c==1)
            {
                system("cls");
                cout<<"#================================#"<<endl;
                cout<<"#    0.  Kembali                 #"<<endl;
                cout<<"#================================#"<<endl;
                cout<<"#           UPDATE DATA          #"<<endl;
                cout<<"#================================#"<<endl;
                cout<<"#    1.  Update Gedung           #"<<endl;
                cout<<"#    2.  Update Lantai           #"<<endl;
                cout<<"#    3.  Update Kamar            #"<<endl;
                cout<<"#    4.  Update Mahasiswa        #"<<endl;
                cout<<"#    5.  Pindah Mahasiswa        #"<<endl;
                cout<<"#================================#"<<endl;
                cout<<" Masukkan pilihan    : ";
                cin>>d;
                switch (d)
                {
                case 1:
                    system("cls");
                    cout<<"#================================#"<<endl;
                    cout<<"#          Update Gedung         #"<<endl;
                    cout<<"#================================#"<<endl;
                    cout<<" Masukan nama gedung yang ingin diperbarui"<<endl;
                    cout<<" Nama Gedung : ";
                    cin>>ig.nama;
                    p = find_gedung(lg,ig);
                    if (p==NULL)
                    {
                        cout<<"=== nama gedung tidak ditemukan ==="<<endl;
                        cout<<"===     tekan 0 untuk kembali    ==="<<endl;
                    }
                    else
                    {
                        editgedung(lg,p);
                    };
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                case 2:
                    system("cls");
                    cout<<"#================================#"<<endl;
                    cout<<"#          Update Lantai         #"<<endl;
                    cout<<"#================================#"<<endl;
                    cout<<" Masukkan Nama Gedung : ";
                    cin>>ig.nama;
                    p = find_gedung(lg,ig);
                    if (p==NULL)
                    {
                        cout<<"=== nama gedung tidak ditemukan ==="<<endl;
                        cout<<"===     tekan 0 untuk kembali    ==="<<endl;
                    }
                    else
                    {
                        cout<<" Masukan nomor lantai yang ingin diperbarui"<<endl;
                        cout<<" Nomor Lantai: ";
                        cin>>il.nomorlantai;
                        q = find_lantai(p->lantai,il);
                        if (p==NULL)
                        {
                            cout<<"=== nomor lantai tidak ditemukan ==="<<endl;
                            cout<<"===    tekan 0 untuk kembali    ==="<<endl;
                        }
                        else
                        {
                            editlantai(p->lantai,q);

                        }
                    };
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                case 3:
                    system("cls");
                    cout<<"#================================#"<<endl;
                    cout<<"#          Update Kamar       #"<<endl;
                    cout<<"#================================#"<<endl;
                    cout<<" Masukkan Nama Gedung : ";
                    cin>>ig.nama;
                    p = find_gedung(lg,ig);
                    if (p==NULL)
                    {
                        cout<<"=== nama gedung tidak ditemukan ==="<<endl;
                        cout<<"===     tekan 0 untuk kembali    ==="<<endl;
                    }
                    else
                    {
                        cout<<" Nomor Lantai: ";
                        cin>>il.nomorlantai;
                        q = find_lantai(p->lantai,il);
                        if (q==NULL)
                        {
                            cout<<"=== nomor lantai tidak ditemukan ==="<<endl;
                            cout<<"===    tekan 0 untuk kembali    ==="<<endl;
                        }
                        else
                        {
                            cout<<" Masukan nomor kamar yang ingin diperbarui"<<endl;
                            cout<<" Nomor Kamar: ";
                            cin>>ik.nomorkamar;
                            r = find_kamar(q->kamar,ik);
                            if (r==NULL)
                            {
                                cout<<"=== nomor kamar tidak ditemukan ==="<<endl;
                                cout<<"===      tekan 0 untuk kembali    ==="<<endl;
                            }
                            else
                            {
                                editkamar(q->kamar,r);

                            }
                        }
                    };
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                case 4:
                    system("cls");
                    cout<<"#================================#"<<endl;
                    cout<<"#         Update Mahasiswa       #"<<endl;
                    cout<<"#================================#"<<endl;
                    cout<<" Masukkan Nama Gedung : ";
                    cin>>ig.nama;
                    p = find_gedung(lg,ig);
                    if (p==NULL)
                    {
                        cout<<"=== nama gedung tidak ditemukan ==="<<endl;
                        cout<<"===     tekan 0 untuk kembali    ==="<<endl;
                    }
                    else
                    {
                        cout<<" Nomor Lantai: ";
                        cin>>il.nomorlantai;
                        q = find_lantai(p->lantai,il);
                        if (q==NULL)
                        {
                            cout<<"=== nomor lantai tidak ditemukan ==="<<endl;
                            cout<<"===    tekan 0 untuk kembali    ==="<<endl;
                        }
                        else
                        {
                            cout<<" Nomor Kamar: ";
                            cin>>ik.nomorkamar;
                            r = find_kamar(q->kamar,ik);
                            if (r==NULL)
                            {
                                cout<<"=== nomor kamar tidak ditemukan ==="<<endl;
                                cout<<"===      tekan 0 untuk kembali    ==="<<endl;
                            }
                            else
                            {
                                cout<<" Masukan nim mahasiswa yang ingin diperbarui"<<endl;
                                cout<<" Nama lokasi  : ";
                                cin>>im.nim;
                                s = find_mahasiswa(r->mahasiswa,im);
                                if (s==NULL)
                                {
                                    cout<<"=== nim mahasiswa tidak ditemukan ==="<<endl;
                                    cout<<"===    tekan 0 untuk kembali    ==="<<endl;
                                }
                                else
                                {
                                    editmahasiswa(r->mahasiswa,s);

                                }
                            }
                        }
                    };
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                case 5:
                    system("cls");
                    cout<<"#================================#"<<endl;
                    cout<<"#          Pindah Mahasiswa      #"<<endl;
                    cout<<"#================================#"<<endl;
                    cout<<" Masukkan Nama Gedung : ";
                    cin>>ig.nama;
                    p = find_gedung(lg,ig);
                    if (p==NULL)
                    {
                        cout<<"=== nama gedung tidak ditemukan ==="<<endl;
                        cout<<"===     tekan 0 untuk kembali    ==="<<endl;
                    }
                    else
                    {
                        cout<<" Nomor Lantai: ";
                        cin>>il.nomorlantai;
                        q = find_lantai(p->lantai,il);
                        if (q==NULL)
                        {
                            cout<<"=== nomor lantai tidak ditemukan ==="<<endl;
                            cout<<"===    tekan 0 untuk kembali    ==="<<endl;
                        }
                        else
                        {
                            cout<<" Nomor Kamar: ";
                            cin>>ik.nomorkamar;
                            r = find_kamar(q->kamar,ik);
                            if (r==NULL)
                            {
                                cout<<"=== nomor kamar tidak ditemukan ==="<<endl;
                                cout<<"===      tekan 0 untuk kembali    ==="<<endl;
                            }
                            else
                            {
                                cout<<" Masukan nim mahasiswa yang ingin diperbarui"<<endl;
                                cout<<" Nim Mahasiswa  : ";
                                cin>>im.nim;
                                s = find_mahasiswa(r->mahasiswa,im);
                                if (s==NULL)
                                {
                                    cout<<"=== nim mahasiswa tidak ditemukan ==="<<endl;
                                    cout<<"===    tekan 0 untuk kembali    ==="<<endl;
                                }
                                else
                                {
                                    pindahmhs(s,lg,ll,lk,lm);
                                    deletemahasiswa(r->mahasiswa,im.nim);
                                    cout<<"=== update mahasiswa sukses  ==="<<endl;
                                    cout<<"=== tekan 0 untuk kembali ==="<<endl;
                                }
                            }
                        }
                    };
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                case 0:
                    c=2;
                    break;
                default :
                    system("cls");
                    cout<<"=== pilihan tidak tersedia dalam menu ==="<<endl;
                    cout<<"    ===   tekan 0 untuk kembali   ===    "<<endl;
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                }
            }
            c=1;
            break;
        case 4:
            system("cls");
            while (c==1)
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
                cin>>d;
                switch (d)
                {
                case 1:
                    viewkmrpnh(lg,ll,lk,lm);
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                case 2:
                    viewkmrksg(lg,ll,lk,lm);
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                case 3:
                    viewkmrisi(lg,ll,lk,lm);
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                case 4:
                    viewall(lg,ll,lk,lm);
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                case 0:
                    c=2;
                    break;
                default :
                    system("cls");
                    cout<<"=== pilihan tidak tersedia dalam menu ==="<<endl;
                    cout<<"    ===   tekan 0 untuk kembali   ===    "<<endl;
                    while ((ch = getch()) != EOF && ch != '0')
                        printf ("%c\n", ch);
                    break;
                }
            }
            c=1;
            break;
        case 5:
            system("cls");
            cout<<"#================================#"<<endl;
            cout<<"#          Cari Mahasiswa        #"<<endl;
            cout<<"#================================#"<<endl;
            cout<<" NIM Mahasiswa  : ";
            cin>>im.nim;
            searchmahsiswa(im.nim,lg);
            while ((ch = getch()) != EOF && ch != '0')
                printf ("%c\n", ch);
            break;
        case 0:
            b=2;
            system("cls");
            cout<<"#================================#"<<endl;
            cout<<"#             KELUAR             #"<<endl;
            cout<<"#================================#"<<endl;
            cout<<"#          Terima Kasih          #"<<endl;
            cout<<"#================================#"<<endl;
            break;
        default :
            system("cls");
            cout<<"=== pilihan tidak tersedia dalam menu ==="<<endl;
            cout<<"    ===   tekan 0 untuk kembali   ===    "<<endl;
            while ((ch = getch()) != EOF && ch != '0')
                printf ("%c\n", ch);
            break;
        }
    }
    return 0;

}

