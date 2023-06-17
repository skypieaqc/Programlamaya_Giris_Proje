/****************************************************************************
**		SAKARYA ÜNİVERSİTESİ BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**					BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				   NESNEYE DAYALI PROGRAMLAMA DERSİ
**						2022-2023 BAHAR DÖNEMİ
**					
**					PROJE NUMARASI: 1
**					ÖĞRENCİ ADI: Ahmet Yunus Çavuş
**					ÖĞRENCİ NUMARASI: B221210082
**					DERSİN ALINDIĞI GRUP: 1. Öğretim A Grubu
**                  
****************************************************************************/

#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

class Urun 
{
private:

	string urunAdi;
	short uretimGun;
	short uretimAy;
	short uretimYil;
	short sonkullanimGun;
	short sonkullanimAy;
	short sonkullanimYil;
	float yuzgramdakalori;
	short StokAdet;
	float maliyet;
	float fiyat;

public:
	
	Urun() :urunAdi(""), yuzgramdakalori(0.0), StokAdet(0), maliyet(0.0), fiyat(0.0), uretimGun(0), uretimAy(0), uretimYil(0), sonkullanimGun(0), sonkullanimAy(0), sonkullanimYil(0)
	{  }

	Urun(string urunad, short uretimgun, short uretimay, short uretimyil, short songun, short sonay, short sonyil, float gramkalori, short adet, float maliyett, float fiyatt)
	{
		urunAdi= urunad;
		uretimGun = uretimgun;
		uretimAy = uretimay;
		uretimYil = uretimyil;
		sonkullanimGun = songun;
		sonkullanimAy = sonay;
		sonkullanimYil = sonyil;
		yuzgramdakalori = gramkalori;
		StokAdet = adet;
		maliyet = maliyett;
		fiyat = fiyatt;
	}

	string geturunAdi()
	{
		return urunAdi;
	}

	short geturetimGun()
	{
		return uretimGun;
	}
	
	short geturetimAy()
	{
		return uretimAy;
	}
	
	short geturetimYil()
	{
		return uretimYil;
	}
	
	short getsonkullanimGun()
	{
		return sonkullanimGun;
	}
	
	short getsonkullanimAy()
	{
		return sonkullanimAy;
	}
	
	short getsonkullanimYil()
	{
		return sonkullanimYil;
	}

	float getyuzgramdakalori()
	{
		return yuzgramdakalori;
	}

	short getStokAdet()
	{
		return StokAdet;
	}

	float getmaliyet()
	{
		return maliyet;
	}

	float getfiyat()
	{
		return fiyat;
	}

	void setUrun()
	{
		string urunad;
		short uretimgun = 0;
		short uretimay = 0;
		short uretimyil = 0;
		short songun = 0;
		short sonay = 0;
		short sonyil = 0;
		float gramkalori = 0.0;
		short adet = 0;
		float maliyett = 0.0;
		float fiyatt = 0.0;

		cout << "\nUrununuzun adini giriniz: "; cin >> urunad;
		cout << "Uretim gununu giriniz: "; cin >> uretimgun;
		cout << "Uretim ayini giriniz: "; cin >> uretimay;
		cout << "Uretim yilini giriniz: "; cin >> uretimyil;
		cout << "Son tuketim gununu giriniz: "; cin >> songun;
		cout << "Son tuketim ayini giriniz: "; cin >> sonay;
		cout << "Son tuketim yilini giriniz: "; cin >> sonyil;
		cout << "Urunun 100 gramdaki kalorisini giriniz: "; cin >> gramkalori;
		cout << "Urunun adetini giriniz: "; cin >> adet;
		cout << "Urunun maliyetini giriniz: "; cin >> maliyett;
		cout << "Urunun fiyatini  giriniz: "; cin >> fiyatt;

		urunAdi = urunad;
		uretimGun = uretimgun;
		uretimAy = uretimay;
		uretimYil = uretimyil;
		sonkullanimGun = songun;
		sonkullanimAy = sonay;
		sonkullanimYil = sonyil;
		yuzgramdakalori = gramkalori;
		StokAdet = adet;
		maliyet = maliyett;
		fiyat = fiyatt;
	}

	void setUrunManuel(string GurunAdi, short GuretimGun, short GuretimAy, short GuretimYil, short GsonkullanimGun, short GsonkullanimAy, short GsonkullanimYil, float Gyuzgramdakalori, short GStokAdet, float Gmaliyet, float Gfiyat)
	{
		urunAdi = GurunAdi;
		uretimGun = GuretimGun;
		uretimAy = GuretimAy;
		uretimYil = GuretimYil;
		sonkullanimGun = GsonkullanimGun;
		sonkullanimAy = GsonkullanimAy;
		sonkullanimYil = GsonkullanimYil;
		yuzgramdakalori = Gyuzgramdakalori;
		StokAdet = GStokAdet;
		maliyet = Gmaliyet;
		fiyat = Gfiyat;
	}

	//Urunleri Depoya Kaydetmeye yarayan fonksiyon.
	void DepoKayit() 
	{
		ofstream dosya;
		dosya.open("Depo.txt", ios::app);

		dosya << endl << urunAdi << " " << StokAdet << " " << maliyet << " " << fiyat << " " << yuzgramdakalori << " " <<
			uretimGun << " " << uretimAy << " " << uretimYil << " " << sonkullanimGun << " " << sonkullanimAy << " " << sonkullanimYil;

		dosya.close();
	}

	//Urunleri Depodan silmeye yarayan fonksiyon.
	void DepoSil()
	{
		ifstream dosya1;
		dosya1.open("Depo.txt");

		ofstream dosya2;
		dosya2.open("GeciciDepo.txt");

		string gurunAdi = " "; short gStokAdet = 0; float gmaliyet = 0; float gfiyat = 0; float gyuzgramdakalori = 0;
		short guretimGun = 0; short guretimAy = 0; short guretimYil = 0; short gsonkullanimGun = 0; short gsonkullanimAy = 0; short gsonkullanimYil = 0;

		//Depo dosyasinin sonuna gelene kadar while dongusu calismaya devam eder.
		while (dosya1 >> gurunAdi >> gStokAdet >> gmaliyet >> gfiyat >> gyuzgramdakalori >> guretimGun >> guretimAy >> guretimYil >> gsonkullanimGun >> gsonkullanimAy >> gsonkullanimYil)
		{
			if (urunAdi == gurunAdi)//Dosyadan okunan isim ile silinecek urunun ismi ayni ise hicbir sey yapilmaz.
			{
				cout << "\n--------Urun silinmistir--------\n";
			}
			else//Dosyadan okunan isim ile silinecek urunun ismi farkli ise bilgiler 2.dosyaya yazdirilir.
			{
				dosya2 << endl << gurunAdi << " " << gStokAdet << " " << gmaliyet << " " << gfiyat << " " << gyuzgramdakalori << " " <<
					guretimGun << " " << guretimAy << " " << guretimYil << " " << gsonkullanimGun << " " << gsonkullanimAy << " " << gsonkullanimYil;
			}
		}

		dosya1.close();
		dosya2.close();
		//1. dosya silinir, 2.dosya 1.dosyanin ismini alir.
		remove("Depo.txt");
		rename("GeciciDepo.txt", "Depo.txt");
	}

	//Urunleri Depodaki bilgilerini guncellemeye yarayan fonksiyon.
	void DepoGuncelle()
	{
		ifstream dosya1;
		dosya1.open("Depo.txt");

		ofstream dosya2;
		dosya2.open("GeciciDepo.txt");

		short GuncelStokAdet = 0; float Guncelmaliyet = 0; float Guncelfiyat = 0; float Guncelyuzgramdakalori = 0;
		short GunceluretimGun = 0; short GunceluretimAy = 0; short GunceluretimYil = 0; short GuncelsonkullanimGun = 0; short GuncelsonkullanimAy = 0; short GuncelsonkullanimYil = 0;
		//Guncel bilgiler kullanicidan alinir.
		cout << "Guncel bilgileri giriniz:\n";
		cout << "Uretim gununu giriniz: "; cin >> GunceluretimGun;
		cout << "Uretim ayini giriniz: "; cin >> GunceluretimAy;
		cout << "Uretim yilini giriniz: "; cin >> GunceluretimYil;
		cout << "Son tuketim gununu giriniz: "; cin >> GuncelsonkullanimGun;
		cout << "Son tuketim ayini giriniz: "; cin >> GuncelsonkullanimAy;
		cout << "Son tuketim yilini giriniz: "; cin >> GuncelsonkullanimYil;
		cout << "Urunun 100 gramdaki kalorisini giriniz: "; cin >> Guncelyuzgramdakalori;
		cout << "Urunun adetini giriniz: "; cin >> GuncelStokAdet;
		cout << "Urunun maliyetini giriniz: "; cin >> Guncelmaliyet;
		cout << "Urunun fiyatini  giriniz: "; cin >> Guncelfiyat;

		string gurunAdi = " "; short gStokAdet = 0; float gmaliyet = 0; float gfiyat = 0; float gyuzgramdakalori = 0;
		short guretimGun = 0; short guretimAy = 0; short guretimYil = 0; short gsonkullanimGun = 0; short gsonkullanimAy = 0; short gsonkullanimYil = 0;
		//Depo dosyasinin sonuna gelene kadar while dongusu calismaya devam eder.
		while (dosya1 >> gurunAdi >> gStokAdet >> gmaliyet >> gfiyat >> gyuzgramdakalori >> guretimGun >> guretimAy >> guretimYil >> gsonkullanimGun >> gsonkullanimAy >> gsonkullanimYil)
		{
			if (urunAdi == gurunAdi)//Dosyadan okunan isim ile silinecek urunun ismi ayni ise guncel bilgiler 2.dosyaya yazdirilir.
			{

				dosya2 << endl << gurunAdi << " " << GuncelStokAdet << " " << Guncelmaliyet << " " << Guncelfiyat << " " << Guncelyuzgramdakalori << " " <<
					GunceluretimGun << " " << GunceluretimAy << " " << GunceluretimYil << " " << GuncelsonkullanimGun << " " << GuncelsonkullanimAy << " " << GuncelsonkullanimYil;

				cout << "\n--------Urun Guncellenmistir--------\n";
			}

			else//Dosyadan okunan isim ile silinecek urunun ismi farkli ise bilgiler 2.dosyaya ayni sekilde yazdirilir.
			{
				dosya2 << endl << gurunAdi << " " << gStokAdet << " " << gmaliyet << " " << gfiyat << " " << gyuzgramdakalori << " " <<
					guretimGun << " " << guretimAy << " " << guretimYil << " " << gsonkullanimGun << " " << gsonkullanimAy << " " << gsonkullanimYil;
			}
		}
		
		dosya1.close();
		dosya2.close();
		//1. dosya silinir, 2.dosya 1.dosyanin ismini alir.
		remove("Depo.txt");
		rename("GeciciDepo.txt", "Depo.txt");
	}

	friend class Yemek;
};

class Yemek
{
private:

	string yemekAdi;
	string malzeme1;
	string malzeme2;
	string malzeme3;
	string malzeme4;
	string malzeme5;
	short stok;
	float maliyet;
	float fiyat;
	float kalori;

public:
	
	Yemek() :yemekAdi(""), malzeme1(""), malzeme2(""), malzeme3(""), malzeme4(""),kalori(0.0) , malzeme5(""), stok(0), maliyet(0.0), fiyat(0.0)
	{  }

	Yemek(string ad, string m1, string m2, string m3, string m4, string m5, short adet, float fiyatt, float maliyett, float kalorii)
	{
		yemekAdi = ad;
		malzeme1 = m1;
		malzeme2 = m2;
		malzeme3 = m3;
		malzeme4 = m4;
		malzeme5 = m5;
		stok = adet;
		maliyet = maliyett;
		fiyat = fiyatt;
		kalori = kalorii;
	}
	
	string getisim()
	{
		return yemekAdi;
	}

	float getkazanc()
	{
		float sonuc = 0;

		sonuc = fiyat - maliyet;

		return sonuc;
	}

	void setYemek()
	{
		string ad, m1, m2, m3, m4,  m5;
		short adet = 0;
		float fiyatt = 0, maliyett = 0, kalorii = 0;
	
		cout << "\nYemeginizin adini giriniz: "; cin >> ad;
		cout << "Yemegin 1 porsiyondaki kalorisini giriniz: "; cin >> kalorii;
		cout << "Yemegin adetini giriniz: "; cin >> adet;
		cout << "Yemegin maliyetini giriniz: "; cin >> maliyett;
		cout << "Yemegin fiyatini  giriniz: "; cin >> fiyatt;
		cout << "Yemekte kullanilan malzemelerin 5 tanesini sirayla giriniz...\n";
		cout << "1.Malzeme: "; cin >> m1;
		cout << "2.Malzeme: "; cin >> m2;
		cout << "3.Malzeme: "; cin >> m3;
		cout << "4.Malzeme: "; cin >> m4;
		cout << "5.Malzeme: "; cin >> m5;

		yemekAdi = ad;
		malzeme1 = m1;
		malzeme2 = m2;
		malzeme3 = m3;
		malzeme4 = m4;
		malzeme5 = m5;
		stok = adet;
		maliyet = maliyett;
		fiyat = fiyatt;
		kalori = kalorii;
	}

	void setYemek1(string ad, short adet, float fiyatt, float maliyett, float kalorii)
	{
		yemekAdi = ad;
		stok = adet;
		maliyet = maliyett;
		fiyat = fiyatt;
		kalori = kalorii;
	}

	void setYemek2(string m1, string m2, string m3, string m4, string m5)
	{
		malzeme1 = m1;
		malzeme2 = m2;
		malzeme3 = m3;
		malzeme4 = m4;
		malzeme5 = m5;
	}

	void setYemekManuel(string ad, string m1, string m2, string m3, string m4, string m5, short adet, float fiyatt, float maliyett, float kalorii)
	{
		yemekAdi = ad;
		malzeme1 = m1;
		malzeme2 = m2;
		malzeme3 = m3;
		malzeme4 = m4;
		malzeme5 = m5;
		stok = adet;
		maliyet = maliyett;
		fiyat = fiyatt;
		kalori = kalorii;
	}
	//Yemekleri yemekcesit dosyasina kaydetmeye yarayan fonksiyon. Ayrica yemekte kullanilan malzemeler depodan silinir, malzeme.txt dosyasina eklenir. Urunler depoda yok ise istek listesine eklenir.
	void yemekKayit()
	{
		ofstream yemekK;
		yemekK.open("yemekcesit.txt", ios::app);

		yemekK << yemekAdi << " " << stok << " " << fiyat << " " << maliyet << " " << kalori << endl;

		ofstream malzemekayit;
		malzemekayit.open("Malzeme.txt", ios::app);

		malzemekayit << yemekAdi << " Malzemeleri----> " << malzeme1 << " " << malzeme2 << " " << malzeme3 << " " << malzeme4 << " " << malzeme5 << "\n\n";
		
		malzemekayit.close();

		string Ad; short uretimG; short uretimA; short uretimY; short sonkullanimG; short sonkullanimA; short sonkullanimY; float Kalori; short adet; float maliyett; float fiyatt;
		string deneme;

		ifstream dosya1;
		dosya1.open("Depo.txt");
		dosya1 >> deneme;
		dosya1.close();
		dosya1.open("Depo.txt");

		ofstream dosya2;
		dosya2.open("GeciciDepo.txt");

		ofstream siparis;
		siparis.open("SiparisListesi.txt", ios::app);

		string m1 = " ", m2 = " ", m3 = " ", m4 = " ", m5 = " ";
		
		if (deneme != "")//Deponun icerisi bos degil ise islemler yapilmaya baslanir.
		{
			while (dosya1 >> Ad >> adet >> maliyett >> fiyatt >> Kalori >> uretimG >> uretimA >> uretimY >> sonkullanimG >> sonkullanimA >> sonkullanimY)//Depo dosyasi okunur.
			{
				if (Ad == malzeme1)//Malzeme depoda var ise adeti azaltilir. Adet 0dan kucuk ise istek listesine urun eklenir. 
				{
					m1 = "VAR";

					adet -= 1;

					dosya2 << Ad << adet << maliyett << fiyatt << Kalori << uretimG << uretimA << uretimY << sonkullanimG << sonkullanimA << sonkullanimY;

					if (adet <= 0)
					{
						siparis << Ad << endl;
					}
				}
				else if (Ad == malzeme2)//Malzeme depoda var ise adeti azaltilir. Adet 0dan kucuk ise istek listesine urun eklenir. 
				{
					m2 = "VAR";

					adet -= 1;

					dosya2 << Ad << adet << maliyett << fiyatt << Kalori << uretimG << uretimA << uretimY << sonkullanimG << sonkullanimA << sonkullanimY;

					if (adet <= 0)
					{
						siparis << Ad << endl;
					}
				}
				else if (Ad == malzeme3)//Malzeme depoda var ise adeti azaltilir. Adet 0dan kucuk ise istek listesine urun eklenir. 
				{
					m3 = "VAR";

					adet -= 1;

					dosya2 << Ad << adet << maliyett << fiyatt << Kalori << uretimG << uretimA << uretimY << sonkullanimG << sonkullanimA << sonkullanimY;

					if (adet <= 0)
					{
						siparis << Ad << endl;
					}
				}
				else if (Ad == malzeme4)//Malzeme depoda var ise adeti azaltilir. Adet 0dan kucuk ise istek listesine urun eklenir. 
				{
					m4 = "VAR";

					adet -= 1;

					dosya2 << Ad << adet << maliyett << fiyatt << Kalori << uretimG << uretimA << uretimY << sonkullanimG << sonkullanimA << sonkullanimY;

					if (adet <= 0)
					{
						siparis << Ad << endl;
					}
				}
				else if (Ad == malzeme5)//Malzeme depoda var ise adeti azaltilir. Adet 0dan kucuk ise istek listesine urun eklenir. 
				{
					m5 = "VAR";

					adet -= 1;

					dosya2 << Ad << adet << maliyett << fiyatt << Kalori << uretimG << uretimA << uretimY << sonkullanimG << sonkullanimA << sonkullanimY;

					if (adet <= 0)
					{
						siparis << Ad << endl;
					}

				}
				else//Malzeme depoda yok ise depoya kayit edilir.
				{
					dosya2 << Ad << adet << maliyett << fiyatt << Kalori << uretimG << uretimA << uretimY << sonkullanimG << sonkullanimA << sonkullanimY;
				}
				if (m1 != "VAR")//Malzeme depoda hic yok ise istek listesine eklenir
				{
					siparis << malzeme1 << endl;
				}
				if (m2 != "VAR")//Malzeme depoda hic yok ise istek listesine eklenir
				{
					siparis << malzeme2 << endl;
				}
				if (m3 != "VAR")//Malzeme depoda hic yok ise istek listesine eklenir
				{
					siparis << malzeme3 << endl;
				}
				if (m4 != "VAR")//Malzeme depoda hic yok ise istek listesine eklenir
				{
					siparis << malzeme4 << endl;
				}
				if (m5 != "VAR")//Malzeme depoda hic yok ise istek listesine eklenir
				{
					siparis << malzeme5 << endl;
				}
			}
		}
		if (deneme == "")//Deponun icerisi bos ise malzemeler istek listesine eklenir.
		{
			siparis << malzeme1 << endl;
			siparis << malzeme2 << endl;
			siparis << malzeme3 << endl;
			siparis << malzeme4 << endl;
			siparis << malzeme5 << endl;
		}
		
		dosya1.close();
		dosya2.close();
		siparis.close();
		//1. dosya silinir, 2.dosya 1.dosyanin ismini alir.
		remove("Depo.txt");
		rename("GeciciDepo.txt", "Depo.txt");

	}
	//Yemekcesit dosyasindan yemekleri silmeye yarayan fonksiyon.
	void yemekSil()
	{
		ifstream dosya1;
		dosya1.open("yemekcesit.txt");

		ofstream dosya2;
		dosya2.open("Geciciyemekcesit.txt");

		string gAd; short gstok = 0; float gfiyat = 0.0, gmaliyet = 0.0, gkalori = 0.0;

		while (dosya1 >> gAd >> gstok >> gfiyat >> gmaliyet >> gkalori)
		{
			if (yemekAdi == gAd)//Okunan deger silinecek urune esit ise yazdirma islemi atlanir.
			{
				cout << "\n--------Urun silinmistir--------\n";
			}
			else//Okunan deger silinecek urune esit degil ise yazdirma islemi 2.dosyaya yapilir.
			{
				dosya2 << gAd << " " << gstok << " " << gfiyat << " " << gmaliyet << " " << gkalori << endl;
			}
		}

		dosya1.close();
		dosya2.close();
		//1. dosya silinir, 2.dosya 1.dosyanin ismini alir.
		remove("yemekcesit.txt");
		rename("Geciciyemekcesit.txt", "yemekcesit.txt");

		ifstream dosya3;
		dosya3.open("Malzeme.txt");

		ofstream dosya4;
		dosya4.open("Gecicimalzeme.txt");

		string yAd, bos, m1, m2, m3, m4, m5;

		while (dosya3 >> yAd >> bos >> m1 >> m2 >> m3 >> m4 >> m5)//Silinen yemekte kullanilan malzemeler malzeme.txt dosyasindan silinir.
		{
			if (yemekAdi == yAd)//Okunan deger silinecek urune esit ise yazdirma islemi atlanir.
			{
				cout << "\n--------Malzemeler silinmistir--------\n";
			}

			else//Okunan deger silinecek urune esit degil ise yazdirma islemi 2.dosyaya yapilir.
			{
				dosya4 << yAd << " Malzemeleri----> " << m1 << " " << m2 << " " << m3 << " " << m4 << " " << m5 << "\n\n";
			} 
		}

		dosya3.close();
		dosya4.close();
		//1. dosya silinir, 2.dosya 1.dosyanin ismini alir.
		remove("Malzeme.txt");
		rename("Gecicimalzeme.txt", "Malzeme.txt");

		ifstream dosya5;
		dosya5.open("Depo.txt");

		ofstream dosya6;
		dosya6.open("Gecicidepo.txt");

		string ad1; short stokA1 = 0; float m11 = 0.0, f11 = 0.0, k11 = 0.0; short t11 = 0, t22 = 0, t33 = 0, t44 = 0, t55 = 0, t66 = 0;

		string M1 = "YOK", M2 = "YOK", M3 = "YOK", M4 = "YOK", M5 = "YOK";

		short ugun = 0, uay = 0, uyil = 0, sgun = 0, say = 0, syil = 0, stok = 0;
		float maliyett = 0.0, fiyatt = 0.0, kalorii = 0.0;

		while (dosya5 >> ad1 >> stokA1 >> m11 >> f11 >> k11 >> t11 >> t22 >> t33 >> t44 >> t55 >> t66)//Malzeme dosyasindan silinen urunler depoya eklenmek uzere isleme alinir.
		{
			if (ad1 == malzeme1)//Malzeme depoda var ise stok adeti artirilir ve 2.dosyaya yazdirilir. Malzemenin depoda var oldugunu gosteren M degiskeni deger alir.
			{
				stokA1 += 1;
				M1 = "VAR";

				dosya6 << endl << ad1 << " " << stokA1 << " " << m11 << " " << f11 << " " << k11 << " " <<
					t11 << " " << t22 << " " << t33 << " " << t44 << " " << t55 << " " << t66;
			}
			else if (ad1 == malzeme2)//Malzeme depoda var ise stok adeti artirilir ve 2.dosyaya yazdirilir. Malzemenin depoda var oldugunu gosteren M degiskeni deger alir.
			{
				stokA1 += 1;
				M2 = "VAR";

				dosya6 << endl << ad1 << " " << stokA1 << " " << m11 << " " << f11 << " " << k11 << " " <<
					t11 << " " << t22 << " " << t33 << " " << t44 << " " << t55 << " " << t66;
			}
			else if (ad1 == malzeme3)//Malzeme depoda var ise stok adeti artirilir ve 2.dosyaya yazdirilir. Malzemenin depoda var oldugunu gosteren M degiskeni deger alir.
			{
				stokA1 += 1;
				M3 = "VAR";

				dosya6 << endl << ad1 << " " << stokA1 << " " << m11 << " " << f11 << " " << k11 << " " <<
					t11 << " " << t22 << " " << t33 << " " << t44 << " " << t55 << " " << t66;
			}
			else if (ad1 == malzeme4)//Malzeme depoda var ise stok adeti artirilir ve 2.dosyaya yazdirilir. Malzemenin depoda var oldugunu gosteren M degiskeni deger alir.
			{
				stokA1 += 1;
				M4 = "VAR";

				dosya6 << endl << ad1 << " " << stokA1 << " " << m11 << " " << f11 << " " << k11 << " " <<
					t11 << " " << t22 << " " << t33 << " " << t44 << " " << t55 << " " << t66;
			}
			else if (ad1 == malzeme5)//Malzeme depoda var ise stok adeti artirilir ve 2.dosyaya yazdirilir. Malzemenin depoda var oldugunu gosteren M degiskeni deger alir.
			{
				stokA1 += 1;
				M5 = "VAR";

				dosya6 << endl << ad1 << " " << stokA1 << " " << m11 << " " << f11 << " " << k11 << " " <<
					t11 << " " << t22 << " " << t33 << " " << t44 << " " << t55 << " " << t66;
			}
			else 
			{
				dosya6 << endl << ad1 << " " << stokA1 << " " << m11 << " " << f11 << " " << k11 << " " <<
					t11 << " " << t22 << " " << t33 << " " << t44 << " " << t55 << " " << t66;
			}

			if (M1 != "VAR")//Malzeme dosyasindan silinen malzeme urun dosyasinda yok ise Malzemenin bilgileri alinir ve depoya kayit edilir.
			{
				stok = 1;
				cout << malzeme1 << " urununun bilgilerini giriniz: \n";
				cout << "Maliyetini giriniz: "; cin >> maliyett;
				cout << "Fiyatini giriniz: "; cin >> fiyatt;
				cout << "100gr'daki Kalorisini giriniz: "; cin >> kalorii;
				cout << "Uretim gununu giriniz: "; cin >> ugun;
				cout << "Uretim ayini giriniz: "; cin >> uay;
				cout << "Uretim yilini giriniz: "; cin >> uyil;
				cout << "Son tuketim gununu giriniz: "; cin >> sgun;
				cout << "Son tuketim ayini giriniz: "; cin >> say;
				cout << "Son tuketim yilini giriniz: "; cin >> syil;
				
				dosya6 << endl << malzeme1 << " " << stok << " " << maliyett << " " << fiyatt << " " << kalorii << " " <<
					ugun << " " << uay << " " << uyil << " " << sgun << " " << say << " " << syil;
			}
			if (M2 != "VAR")//Malzeme dosyasindan silinen malzeme urun dosyasinda yok ise Malzemenin bilgileri alinir ve depoya kayit edilir.
			{
				stok = 1;
				cout << malzeme2 << " urununun bilgilerini giriniz: \n";
				cout << "Maliyetini giriniz: "; cin >> maliyett;
				cout << "Fiyatini giriniz: "; cin >> fiyatt;
				cout << "100gr'daki Kalorisini giriniz: "; cin >> kalorii;
				cout << "Uretim gununu giriniz: "; cin >> ugun;
				cout << "Uretim ayini giriniz: "; cin >> uay;
				cout << "Uretim yilini giriniz: "; cin >> uyil;
				cout << "Son tuketim gununu giriniz: "; cin >> sgun;
				cout << "Son tuketim ayini giriniz: "; cin >> say;
				cout << "Son tuketim yilini giriniz: "; cin >> syil;

				dosya6 << endl << malzeme2 << " " << stok << " " << maliyett << " " << fiyatt << " " << kalorii << " " <<
					ugun << " " << uay << " " << uyil << " " << sgun << " " << say << " " << syil;
			}
			if (M3 != "VAR")//Malzeme dosyasindan silinen malzeme urun dosyasinda yok ise Malzemenin bilgileri alinir ve depoya kayit edilir.
			{
				stok = 1;
				cout << malzeme3 << " urununun bilgilerini giriniz: \n";
				cout << "Maliyetini giriniz: "; cin >> maliyett;
				cout << "Fiyatini giriniz: "; cin >> fiyatt;
				cout << "100gr'daki Kalorisini giriniz: "; cin >> kalorii;
				cout << "Uretim gununu giriniz: "; cin >> ugun;
				cout << "Uretim ayini giriniz: "; cin >> uay;
				cout << "Uretim yilini giriniz: "; cin >> uyil;
				cout << "Son tuketim gununu giriniz: "; cin >> sgun;
				cout << "Son tuketim ayini giriniz: "; cin >> say;
				cout << "Son tuketim yilini giriniz: "; cin >> syil;

				dosya6 << endl << malzeme3 << " " << stok << " " << maliyett << " " << fiyatt << " " << kalorii << " " <<
					ugun << " " << uay << " " << uyil << " " << sgun << " " << say << " " << syil;
			}
			if (M4 != "VAR")//Malzeme dosyasindan silinen malzeme urun dosyasinda yok ise Malzemenin bilgileri alinir ve depoya kayit edilir.
			{
				stok = 1;
				cout << malzeme4 << " urununun bilgilerini giriniz: \n";
				cout << "Maliyetini giriniz: "; cin >> maliyett;
				cout << "Fiyatini giriniz: "; cin >> fiyatt;
				cout << "100gr'daki Kalorisini giriniz: "; cin >> kalorii;
				cout << "Uretim gununu giriniz: "; cin >> ugun;
				cout << "Uretim ayini giriniz: "; cin >> uay;
				cout << "Uretim yilini giriniz: "; cin >> uyil;
				cout << "Son tuketim gununu giriniz: "; cin >> sgun;
				cout << "Son tuketim ayini giriniz: "; cin >> say;
				cout << "Son tuketim yilini giriniz: "; cin >> syil;

				dosya6 << endl << malzeme4 << " " << stok << " " << maliyett << " " << fiyatt << " " << kalorii << " " <<
					ugun << " " << uay << " " << uyil << " " << sgun << " " << say << " " << syil;
			}
			if (M5 != "VAR")//Malzeme dosyasindan silinen malzeme urun dosyasinda yok ise Malzemenin bilgileri alinir ve depoya kayit edilir.
			{
				stok = 1;
				cout << malzeme5 << " urununun bilgilerini giriniz: \n";
				cout << "Maliyetini giriniz: "; cin >> maliyett;
				cout << "Fiyatini giriniz: "; cin >> fiyatt;
				cout << "100gr'daki Kalorisini giriniz: "; cin >> kalorii;
				cout << "Uretim gununu giriniz: "; cin >> ugun;
				cout << "Uretim ayini giriniz: "; cin >> uay;
				cout << "Uretim yilini giriniz: "; cin >> uyil;
				cout << "Son tuketim gununu giriniz: "; cin >> sgun;
				cout << "Son tuketim ayini giriniz: "; cin >> say;
				cout << "Son tuketim yilini giriniz: "; cin >> syil;

				dosya6 << endl << malzeme5 << " " << stok << " " << maliyett << " " << fiyatt << " " << kalorii << " " <<
					ugun << " " << uay << " " << uyil << " " << sgun << " " << say << " " << syil;
			}
		}

		dosya5.close();
		dosya6.close();
		//1. dosya silinir, 2.dosya 1.dosyanin ismini alir.
		remove("Depo.txt");
		rename("Gecicidepo.txt", "Depo.txt"); 
	}
	//Yemekcesit dosyasindaki bilgileri guncellemeye yarayan fonksiyon.
	void yemekGuncelle()
	{

		string gAd; short gstok = 0; float gfiyat = 0.0, gmaliyet = 0.0, gkalori = 0.0;
		short a1 = 0; float f1 = 0.0, m1 = 0.0, k1 = 0.0;

		cout << "Guncel bilgileri sirayla giriniz.\n";			//Guncellenecek bilgiler kullanicidan alinir.
		cout << "Yemek adeti: "; cin >> gstok;
		cout << "Yemek fiyati: "; cin >> gfiyat;
		cout << "Yemek maliyeti: "; cin >> gmaliyet;
		cout << "Yemek kalorisi: "; cin >> gkalori;

		ifstream dosya1;
		dosya1.open("yemekcesit.txt");

		ofstream dosya2;
		dosya2.open("geciciyemekcesit.txt");

		while (dosya1 >> gAd >> a1 >> f1 >> m1 >> k1)//Yemek dosyasi okunur.
		{
			if (yemekAdi == gAd)//Okunan isim guncellenecek urunun ismiyle ayni ise guncel bilgiler 2.dosyaya yazdirilir.
			{
				dosya2 << gAd << " " << gstok << " " << gfiyat << " " << gmaliyet << " " << gkalori << endl;

				cout << "Yemek guncellenmistir.\n";
			}
			else
			{
				dosya2 << gAd << " " << a1 << " " << f1 << " " << m1 << " " << k1 << endl;
			}
		}

		dosya1.close();
		dosya2.close();

		remove("yemekcesit.txt");
		rename("geciciyemekcesit.txt", "yemekcesit.txt");

		stok = gstok;
		maliyet = gmaliyet;
		fiyat = gfiyat;
		kalori = gkalori;

	}

	void yemekGuncelle2(short stokmiktari)
	{
		stok += stokmiktari;

		string gAd; short a1 = 0; float f1 = 0.0, m1 = 0.0, k1 = 0.0;

		ifstream dosya1;
		dosya1.open("yemekcesit.txt");

		ofstream dosya2;
		dosya2.open("geciciyemekcesit.txt");

		while (dosya1 >> gAd >> a1 >> f1 >> m1 >> k1)
		{
			if (yemekAdi == gAd)
			{
				dosya2 << gAd << " " << stok << " " << f1 << " " << m1 << " " << k1 << endl;
			}
			else
			{
				dosya2 << gAd << " " << a1 << " " << f1 << " " << m1 << " " << k1 << endl;
			}
		}
		dosya1.close();
		dosya2.close();
		//1. dosya silinir, 2.dosya 1.dosyanin ismini alir.
		remove("yemekcesit.txt");
		rename("geciciyemekcesit.txt", "yemekcesit.txt");
	}
	//Gunluk yemek uretim miktarini belirlemeye yardimci olan fonksiyon.
	void GunlukUretim(int uretim)
	{
		stok += uretim;
	}


};



int main(void) 
{

	char secim = 1, devam = 'h', secim2 = 1;
	short urunsayaci = -1; short yemeksayaci = -1;

	Urun urun[100];
	Yemek yemek[40];

	string GurunAdi; short GuretimGun = 0;  short GuretimAy = 0; short GuretimYil = 0; short GsonkullanimGun = 0;  short GsonkullanimAy = 0; short GsonkullanimYil = 0; float Gyuzgramdakalori = 0; short GStokAdet = 0; float Gmaliyet = 0; float Gfiyat = 0;
	string m1, m2, m3, m4, m5;

	ifstream DepoOku;
	DepoOku.open("Depo.txt");
	//Deponun icerisinde urunler kayitli ise var olan urunleri program icerisinde degisiklik yapabilmek icin tanimliyoruz.
	while (DepoOku >> GurunAdi >> GStokAdet >> Gmaliyet >> Gfiyat >> Gyuzgramdakalori >> GuretimGun >> GuretimAy >> GuretimYil >> GsonkullanimGun >> GsonkullanimAy >> GsonkullanimYil)
	{
		urunsayaci += 1;

		urun[urunsayaci].setUrunManuel(GurunAdi, GuretimGun, GuretimAy, GuretimYil, GsonkullanimGun, GsonkullanimAy, GsonkullanimYil, Gyuzgramdakalori, GStokAdet, Gmaliyet, Gfiyat);
	}
	DepoOku.close();

	string yemekAdi = " "; float yemekKalori = 0; float yemekFiyat = 0; float yemekMaliyet = 0; short yemekAdet = 0;

	ifstream YemekOku;
	YemekOku.open("yemekcesit.txt");
	YemekOku >> yemekAdi;
	YemekOku.close();

	ifstream malzemeOku;
	malzemeOku.open("Malzeme.txt");
	YemekOku.open("yemekcesit.txt");
	if (yemekAdi == " ")//Yemekcesit dosyasi bos ise lokantanin her zaman yaptigi yemekler kayit edilir.
	{
		yemek[0].setYemekManuel("Kurufasulye", "fasulye", "sogan", "biber", "salca", "yag", 0, 25, 10, 300);
		yemek[0].yemekKayit();

		yemek[1].setYemekManuel("Karniyarik", "patlican", "yag", "sogan", "biber", "kiyma", 0, 25, 10, 300);
		yemek[1].yemekKayit();

		yemek[2].setYemekManuel("TavukDoner", "tavuk", "yag", "sogan", "yogurt", "kekik", 0, 25, 10, 300);
		yemek[2].yemekKayit();

		yemek[3].setYemekManuel("Lahmacun", "kiyma", "biber", "sogan", "maydanoz", "domates", 0, 25, 10, 300);
		yemek[3].yemekKayit();

		yemek[4].setYemekManuel("İcliKofte", "bulgur", "irmik", "un", "karabiber", "domates", 0, 25, 10, 300);
		yemek[4].yemekKayit();

		yemek[5].setYemekManuel("CigKofte", "bulgur", "tuz", "isot", "sogan", "domates", 0, 25, 10, 300);
		yemek[5].yemekKayit();

		yemek[6].setYemekManuel("YaprakSarma", "yaprak", "pirinc", "domates", "yag", "sogan", 0, 25, 10, 300);
		yemek[6].yemekKayit();

		yemek[7].setYemekManuel("Iskender", "doner", "domates", "yogurt", "yag", "salca", 0, 25, 10, 300);
		yemek[7].yemekKayit();

		yemek[8].setYemekManuel("Manti", "kiyma", "sogan", "hamur", "yogurt", "karabiber", 0, 25, 10, 300);
		yemek[8].yemekKayit();

		yemek[9].setYemekManuel("TarhanaCorbasi", "tarhana", "nane", "yag", "salca", "biber", 0, 25, 10, 300);
		yemek[9].yemekKayit();

		yemek[10].setYemekManuel("Kavurma", "yag", "et", "sogan", "biber", "domates", 0, 25, 10, 300);
		yemek[10].yemekKayit();

		yemek[11].setYemekManuel("TasKebabi", "et", "patates", "havuc", "sogan", "salca", 0, 25, 10, 300);
		yemek[11].yemekKayit();

		yemek[12].setYemekManuel("MercimekPilavi", "mercimek", "bulgur", "tuz", "su", "yag", 0, 25, 10, 300);
		yemek[12].yemekKayit();

		yemek[13].setYemekManuel("InegolKofte", "kiyma", "karbonat", "un", "sogan", "tuz", 0, 25, 10, 300);
		yemek[13].yemekKayit();
	
		yemek[14].setYemekManuel("EtliEkmek", "kiyma", "domates", "biber", "sogan", "yag", 0, 25, 10, 300);
		yemek[14].yemekKayit();

		yemek[15].setYemekManuel("KadinbuduKofte", "kiyma", "yumurta", "pirinc", "sogan", "kimyon", 0, 25, 10, 300);
		yemek[15].yemekKayit();

		yemek[16].setYemekManuel("Pilav", "yag", "sehriye", "pirinc", "sogan", "tarcin", 0, 25, 10, 300);
		yemek[16].yemekKayit();

		yemek[17].setYemekManuel("MercimekCorbasi", "mercimek", "un", "havuc", "sogan", "tuz", 0, 25, 10, 300);
		yemek[17].yemekKayit();

		yemek[18].setYemekManuel("AdanaKebab", "kiyma", "yag", "biber", "sogan", "salca", 0, 25, 10, 300);
		yemek[18].yemekKayit();

		yemek[19].setYemekManuel("KiymaliPatlican", "patlican", "kiyma", "sogan", "yag", "biber", 0, 25, 10, 300);
		yemek[19].yemekKayit();

		yemeksayaci = 19;
  	}
	else//Yemekcesit dosyasi zaten var ise icerisinde kayitli yemekler program icerisinde degisiklik yapabilmek icin tanimliyoruz.
	{
		while (YemekOku >> GurunAdi >> GStokAdet >> Gfiyat >> Gmaliyet >> Gyuzgramdakalori)
		{
			malzemeOku >> GurunAdi >> GuretimGun >> m1 >> m2 >> m3 >> m4 >> m5;

			yemeksayaci += 1;

			yemek[yemeksayaci].setYemek1(GurunAdi, GStokAdet, Gfiyat, Gmaliyet, Gyuzgramdakalori);

			yemek[yemeksayaci].setYemek2(m1, m2, m3, m4, m5);

		}
	}
	malzemeOku.close();
	YemekOku.close();
	

	char exit = 'h';
	short gun = 1;
	char skip = 'n';
	short gunlukyemek = 0;
	string geciciisim;
	short gecicisayac = 0;
	short satis = 0;
	short yemeksirasi = -1;
	float kazanc = 0, Tkazanc = 0;
	short newline = 0;

	do
	{
		cout << gun << ". gun icin her yemekten kac tane yapilacagini sirayla giriniz: \n";

		ifstream satilanYemeklerO;
		ofstream satilanYemekler;
		satilanYemekler.open("satilanyemekler.txt");
		satilanYemekler << "";			//Satilanyemekler dosyasinin icerisi bosaltilir. 
		satilanYemekler.close();

		ifstream uretilenYemeklerO;
		ofstream uretilenYemekler;
		uretilenYemekler.open("uretilenyemekler.txt");
		uretilenYemekler << "";			//uretilenyemeler dosyasinin icerisi bosaltilir.
		uretilenYemekler.close();

		for (int i = 0; i <= yemeksayaci; i++)//Kac tane yemek kayitli ise her biri icin uretim adeti kullanicidan alinir.
		{
			geciciisim = yemek[i].getisim();

			cout << geciciisim << " adli yemekten kac tane yapilacak: ";	cin >> gunlukyemek;

			uretilenYemekler.open("uretilenyemekler.txt", ios::app);		//Uretilicek olan yemekler ileride rapor cikarmak icin uretilenyemekler dosyasina kayit edilir.
			if (gunlukyemek != 0)
			{
				uretilenYemekler << geciciisim << endl;
			}
			uretilenYemekler.close();

			yemek[i].GunlukUretim(gunlukyemek);

			yemek[i].yemekGuncelle2(0);
		}

		skip = 'n';

		do
		{
			cout << "\nGun  " << gun << endl;
			cout << "--------Islem Listesi--------\n";
			cout << "1.Islem Depo Islemleri\n";
			cout << "2.Islem Deponun Raporunu Cikar\n";
			cout << "3.Islem Yemek Islemleri\n";
			cout << "4.Islem Yemek Cesidi Raporu Cikar\n";
			cout << "5.Islem Satis Yap\n";
			cout << "6.Islem Gun Icindeki Islemler Raporu\n";
			cout << "7.Islem Gunu Bitir\n";
			cout << "8.Islem Programdan Cik\n";

			cout << "\nYapmak Istedigin Islemi Tusla: ";

			do//Kullanicidan dogru islem yapmasi saglanir.
			{
				secim = _getch();

				if (!(secim == '1' || secim == '2' || secim == '3' || secim == '4' || secim == '5' || secim == '6' || secim == '7' || secim == '8'))
				{
					cout << "\nLutfen Gecerli Bir Islem Tuslayin (1/2/3/4/5/6/7/8):  ";
				}

			} while (!(secim == '1' || secim == '2' || secim == '3' || secim == '4' || secim == '5' || secim == '6' || secim == '7' || secim == '8'));

			string SilinecekUrun;
			string GuncellenecekUrun;
			short urunsirasi = -1;

			switch (secim)//Kullanicinin secimine gore islemler yapilir.
			{
			case '1'://Depo islemleri kullaniciya sunulur.

				cout << "\n\n--------Islem Listesi--------\n";
				cout << "1.Islem Depo Urun Ekleme\n";
				cout << "2.Islem Depodan Urun Silme\n";
				cout << "3.Islem Depoyu Guncelle\n";
				cout << "\nYapmak Istedigin Islemi Tusla: ";
				//Kullanicidan gecerli islem bilgisi alinir.
				do
				{
					secim2 = _getch();

					if (!(secim2 == '1' || secim2 == '2' || secim2 == '3'))
					{
						cout << "\nLutfen Gecerli Bir Islem Tuslayin (1/2/3):  ";
					}

				} while (!(secim2 == '1' || secim2 == '2' || secim2 == '3'));

				if (secim2 == '1')//kullanici 1.islemi tercih ederse gerceklestirilir.
				{
					urunsayaci += 1;

					urun[urunsayaci].setUrun();		//Depoya urun eklemek uzere urun verileri kullanicidan alinir.

					urun[urunsayaci].DepoKayit();	//Urun depoya kayit edilir.
				}

				else if (secim2 == '2')//kullanici 2.islemi tercih ederse gerceklestirilir.
				{
					cout << "Silmek Istedigin Urunun Ismini Giriniz: "; cin >> SilinecekUrun;

					DepoOku.open("Depo.txt");
					//Silinecek urunun kayitli oldugu dizideki sirasi urunsirasi sayesinde bulunur.
					do
					{
						urunsirasi += 1;

						DepoOku >> GurunAdi >> GStokAdet >> Gmaliyet >> Gfiyat >> Gyuzgramdakalori >> GuretimGun >> GuretimAy >> GuretimYil >>
							GsonkullanimGun >> GsonkullanimAy >> GsonkullanimYil;

					} while (GurunAdi != SilinecekUrun);

					DepoOku.close();

					urun[urunsirasi].DepoSil(); // urun depodan silinir.

					urunsirasi = -1;			//urunsirasi -1 degerini tekrar kullanilmak icin alir.
				}

				else if (secim2 == '3')//kullanici 3.islemi tercih ederse gerceklestirilir.
				{
					cout << "Guncellemek Istedigin Urunun Ismini Giriniz: "; cin >> GuncellenecekUrun;

					DepoOku.open("Depo.txt");
					//guncellenecek urunun kayitli oldugu dizideki sirasi urunsirasi sayesinde bulunur.
					do
					{
						urunsirasi += 1;

						DepoOku >> GurunAdi >> GStokAdet >> Gmaliyet >> Gfiyat >> Gyuzgramdakalori >> GuretimGun >> GuretimAy >> GuretimYil >>
							GsonkullanimGun >> GsonkullanimAy >> GsonkullanimYil;

					} while (GurunAdi != GuncellenecekUrun);

					DepoOku.close();

					urun[urunsirasi].DepoGuncelle();	//urun depoda guncellenir

					urunsirasi = -1;
				}

				break;

			case '2'://Depo dosyasi okunarak ekrana yazdirilir.

				DepoOku.open("Depo.txt");

				cout << "\n" << setw(50) << "| DEPO RAPOR |\n\n" << setw(15) << left << "|Urun Adi" << setw(10) << left << "|Stok" << setw(11) << left << "|Maliyet" << setw(11) << left << "|Fiyat"
					<< setw(13) << left << "|Kalori" << setw(20) << left << "|Uretim Tarihi" << setw(13) << left << "|Son Kullanim Tarihi\n\n";

				while (DepoOku >> GurunAdi >> GStokAdet >> Gmaliyet >> Gfiyat >> Gyuzgramdakalori >> GuretimGun >> GuretimAy >> GuretimYil >> GsonkullanimGun >> GsonkullanimAy >> GsonkullanimYil)
				{
					cout << setw(16) << left << GurunAdi << setw(11) << left << GStokAdet << setw(11) << left << Gmaliyet << setw(11) << left << Gfiyat << setw(14) << left << Gyuzgramdakalori <<
						GuretimGun << "/" << GuretimAy << "/" << GuretimYil << "\t\t    " << GsonkullanimGun << "/" << GsonkullanimAy << "/" << GsonkullanimYil << endl;

				}

				DepoOku.close();

				break;

			case '3':

				cout << "--------Islem Listesi--------\n";
				cout << "1.Islem Yemek Cesidi Ekleme\n";
				cout << "2.Islem Yemek Cesidi Silme\n";
				cout << "3.Islem Yemek Cesidi Guncelle\n";
				cout << "\nYapmak Istedigin Islemi Tusla: ";

				do
				{
					secim2 = _getch();

					if (!(secim2 == '1' || secim2 == '2' || secim2 == '3'))
					{
						cout << "\nLutfen Gecerli Bir Islem Tuslayin (1/2/3):  ";
					}

				} while (!(secim2 == '1' || secim2 == '2' || secim2 == '3'));

				if (secim2 == '1')
				{
					yemeksayaci += 1;

					yemek[yemeksayaci].setYemek();		//Yemek bilgileri kullanicidan alinir/

					yemek[yemeksayaci].yemekKayit();	//Bilgileri alinan yemek yemekdosyasindaki, malzemedosyasindaki ve depodaki islemleri gerceklestirilir.
				}

				else if (secim2 == '2')
				{
					cout << "Silmek Istedigin Yemegin Ismini Giriniz: "; cin >> SilinecekUrun;

					YemekOku.open("yemekcesit.txt");
					//silinecek urunun kayitli oldugu dizideki sirasi urunsirasi sayesinde bulunur.
					do
					{
						urunsirasi += 1;

						YemekOku >> yemekAdi >> GStokAdet >> Gfiyat >> Gmaliyet >> Gyuzgramdakalori;

					} while (yemekAdi != SilinecekUrun);

					YemekOku.close();

					yemek[urunsirasi].yemekSil();	//Yemek ile alakali bilgiler butun dosyalardan silinir.

					urunsirasi = -1;
				}

				else if (secim2 == '3')
				{
					cout << "Guncellemek Istedigin Yemegin Ismini Giriniz: "; cin >> GuncellenecekUrun;

					YemekOku.open("yemekcesit.txt");
					//Guncellenecek urunun kayitli oldugu dizideki sirasi urunsirasi sayesinde bulunur.
					do
					{
						urunsirasi += 1;

						YemekOku >> yemekAdi >> GStokAdet >> Gfiyat >> Gmaliyet >> Gyuzgramdakalori;

					} while (yemekAdi != SilinecekUrun);

					YemekOku.close();

					yemek[urunsirasi].yemekGuncelle();	//Yemek bilgileri guncellenir ve kayit edilir.

					urunsirasi = -1;
				}

				break;

			case '4'://Yemek dosyasindan okunan bilgiler ekrana yazdirilir.

				YemekOku.open("yemekcesit.txt");

				cout << "\n\n" << setw(40) << "| YEMEK CESIT RAPOR |\n\n" << setw(25) << left << "|Yemek Adi" << setw(10) << left << "|Adet" << setw(11) << left << "|Maliyet" << setw(11) << left << "|Fiyat"
					<< setw(13) << left << "|Kalori\n\n";

				while (YemekOku >> GurunAdi >> GStokAdet >> Gfiyat >> Gmaliyet >> Gyuzgramdakalori)
				{
					cout << setw(26) << left << GurunAdi << setw(11) << left << GStokAdet << setw(11) << left << Gfiyat << setw(11) << left << Gmaliyet << setw(14) << left << Gyuzgramdakalori << endl;
				}

				YemekOku.close();

				break;

			case '5':

				cout << "Satilan yemek: "; cin >> geciciisim; //Kullanicidan satilan yemegin bilgileri alinir.
				cout << "Kac adet satildi: "; cin >> satis;		//Kullanicidan kac adet satildiginin bilgisi alinir.
				//satilan urunun kayitli oldugu dizideki sirasi urunsirasi sayesinde bulunur.
				YemekOku.open("yemekcesit.txt");
				do
				{
					yemeksirasi += 1;

					YemekOku >> GurunAdi >> GStokAdet >> Gfiyat >> Gmaliyet >> Gyuzgramdakalori;

				}while (GurunAdi != geciciisim);
				YemekOku.close();

				kazanc = yemek[yemeksirasi].getkazanc();		//getkazanc fonksiyonu ile 1 satistan elde edilen kar hesaplanir.

				kazanc *= satis;								//Kac adet satildi ise kar o sayi ile carpili.

				Tkazanc += kazanc;								//Elde edilen butun karlar toplanir.

				yemek[yemeksirasi].yemekGuncelle2(-satis);		//Satilan yemegin stok miktari guncellenir/

				satilanYemekler.open("satilanyemekler.txt", ios::app);	

				satilanYemekler << geciciisim << endl;				//Satilan yemekler rapor cikartabilmek icin dosyaya kayit edilir.

				satilanYemekler.close();

				break;

			case '6':		//Gun icerisinde yapilan islemlerin raporu kayit edilen dosyalar sayesinde cikartilir.

				cout << "\n\nGun icerisinde Uretilen Yemekler\n";	

				uretilenYemeklerO.open("uretilenyemekler.txt");
				while (uretilenYemeklerO >> geciciisim)		//Okunan degerler ekrana yazdirilir.
				{
					newline += 1;
					
					cout << setw(20) << left << geciciisim;
					
					if (newline % 5 == 0)
					{
						cout << endl;
					}
				}
				uretilenYemeklerO.close();
				newline = 0;
				cout << endl;

				cout << "\n\nGun icerisinde Satilan Yemekler\n";
				
				satilanYemeklerO.open("satilanyemekler.txt");
				while (satilanYemeklerO >> geciciisim)		//Okunan degerler ekrana yazdirilir.
				{
					newline += 1;

					cout << setw(20) << left << geciciisim;

					if (newline % 5 == 0)
						cout << endl;
					
				}
				satilanYemeklerO.close();
				newline = 0;
				cout << endl;

				cout << gun << ". gunde su ana kadar elde edilen kar miktari: " << Tkazanc << endl;

				cout << gun << ". gunde elde kalan yemekler: \n";

				YemekOku.open("yemekcesit.txt");
				while (YemekOku >> GurunAdi >> GStokAdet >> Gfiyat >> Gmaliyet >> Gyuzgramdakalori)
				{
					if (GStokAdet != 0)		//Okunan degerler ekrana yazdirilir.
					{
						newline += 1;

						cout << setw(20) << left << GurunAdi;

						if (newline % 5 == 0)
							cout << endl;
					}
				}
				YemekOku.close();

				break;

			case '7':		//Bir sonraki gune gecmek icin skip degiskeni s degerini alir.

				gun += 1;

				skip = 's';

				break;

			case '8':		//Programdan cikilmasi icin exit degiskeni e degerini alir.

				exit = 'e';

				break;

			}
			// exit degiskeninin degeri e veya skip degiskeninin degeri s ise soru sorulmaz 
			if ((exit != 'e') && (skip != 's'))
			{
				cout << "Islem Yapmaya Devam Etmek Ister Misin ? (e/h)";
				devam = _getch();	
			}
			system("cls");

		} while ((devam == 'e' || devam == 'E') && (exit == 'h') && (skip != 's'));	

	
}while (exit == 'h');//exit degeri e ise programdan cikilir.

	//Gun icerisinde yapilan islemleri kolaylastirmak icin acilan dosyalar silinir.
	remove("uretilenyemekler.txt");
	remove("satilanyemekler.txt");

	return 0;

}
