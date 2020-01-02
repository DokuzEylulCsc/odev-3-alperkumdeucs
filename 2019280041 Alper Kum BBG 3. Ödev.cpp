#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*Bu program öðrenciler sadece 12 soru yanýtladýðýnda doðru çalýþmaktadýr.
Öðrencilerin yapýtðý soru sayýsýnýn 12'den farklý olmasý programýn hatalý çalýþmasýna sebep olmaktadýr.
Öðrenci sayýsýnýn deðiþmesi programýn çalýþmasýný etkilememektedir.
Medyan bulmak için sýralama kodu Quiz 2'de kullandýðým Insertion Sort kodudur.
Bilginize sunarým saygýdeðer hocalarým.*/

void swapSort(int &valueA, int &valueB);


int main() {
	cout << "*****Alper Kum 2019280041 DEUCS Bilgisayar Bilimlerine Giris 3. Odev*****" << endl;
	cout << "C++ Optik Okuyucu" << endl;
	cout << "Islem baslatiliyor..." << endl;
	ifstream inputFile("input.txt");
	ofstream outputFile("output.txt");
	string soruSayi;
	string cevapAnahtari;
	string ogrenciCevap;
	string ogrenciNumara;
	int ogrenci = 0;
	int score = 0;
	int puan[ogrenci];
	int soruSayKont = -1;
   		getline(inputFile, soruSayi);
   		cout << "Sinavin soru sayisi: " << soruSayi << endl;
   		getline(inputFile, cevapAnahtari);
   		for (int iCA = 0; iCA < cevapAnahtari.length(); iCA++)
			{
				if (cevapAnahtari[iCA] == ',')
				{
					cevapAnahtari[iCA] = ' ';
				}
			}
			cout << endl;
			while(getline(inputFile, ogrenciCevap)){
   			for (int iOC = 11; iOC < ogrenciCevap.length(); iOC++)
			{
						if (ogrenciCevap[iOC] == ',')
						{
							ogrenciCevap[iOC] = ' ';
			 			}
			 			else
			 			{
			 				soruSayKont++;
						}
					}
		for (int iOgrenciKontrol = 11; iOgrenciKontrol < ogrenciCevap.length(); iOgrenciKontrol++)
		{
			if (ogrenciCevap[iOgrenciKontrol] == cevapAnahtari[iOgrenciKontrol - soruSayKont] && ogrenciCevap[iOgrenciKontrol] != ' ')
			 {
			 	score +=4;
			 }
			else if (ogrenciCevap[iOgrenciKontrol] != cevapAnahtari[iOgrenciKontrol - soruSayKont] && ogrenciCevap[iOgrenciKontrol] != ' ')
			{
				score--;
			}
		}
		if (score > 0)
			{
				score = score;
			}
			else
			{
				score = 0;
			}
			puan[ogrenci] = score;
			for (int iOgrenciPuan = 0; iOgrenciPuan < 10; iOgrenciPuan++)
			{
				outputFile << ogrenciCevap[iOgrenciPuan];
			}
			outputFile << "," << puan[ogrenci] << endl;
		ogrenci++;
		score = 0;
		soruSayKont = -1;
   		}
   		inputFile.close();
   		cout << "Sinava giren ogrenci sayisi: " << ogrenci << endl;
   		int puanBuyuk = puan[0];
   		int puanKucuk = puan[0];
   		int iPuan = 0;
   		int puanMedyan;
   		int puanAciklik;
		int puanSum = 0;
   		float puanOrt = 0;
   		for (iPuan = 0; iPuan < ogrenci; iPuan++)
   		{
   			if (puan[iPuan] > puanBuyuk)
			   {
			   	puanBuyuk = puan[iPuan];
			   }
			if (puan[iPuan] < puanKucuk)
			{
				puanKucuk = puan[iPuan];
			}
			puanSum += puan[iPuan];	
		}
		int scanStart;
		int indexAbsolute;
		int indexMin;
		int valueMin;
		for (scanStart=0; scanStart < ogrenci; scanStart++){
		indexMin = scanStart;
		valueMin = puan[scanStart];
		for(indexAbsolute = scanStart+1; indexAbsolute< ogrenci; indexAbsolute++)
		{
			if (puan[indexAbsolute]<valueMin)
			{
				valueMin = puan[indexAbsolute];
				indexMin = indexAbsolute;
				cout << valueMin;
			}
			swapSort(puan[indexMin], puan[scanStart]);
		}
		}
		if (iPuan%2 == 0)
		{
			puanMedyan = (puan[iPuan/2]+puan[iPuan/2-1])/2;
		}
		else
		{
			puanMedyan = puan[iPuan/2];
		}
		puanOrt = puanSum/(ogrenci);
		puanAciklik = puanBuyuk - puanKucuk;
		cout << "Sinavin en yuksek notu: " << puanBuyuk << endl << "Sinavin en dusuk notu: " << puanKucuk << endl << "Sinavin ortalamasi: " << puanOrt << endl << "Sinavin medyani: " << puanMedyan << endl << "Sinavin not acikligi: " << puanAciklik << endl;
		outputFile << puanBuyuk << "," << puanKucuk << "," << puanOrt << "," << puanMedyan << "," << puanAciklik;
		outputFile.close();
		cout << "Islem tamamlandi... ";
		system("pause");
	}
		//https://stackoverflow.com/questions/16746963/c-reading-a-specific-line-from-a-text-file-and-comparing-it-with-an-input
		//https://stackoverflow.com/questions/20739453/using-getline-with-file-input-in-c
		//http://biliminrengi.blogspot.com/2015/01/c-if-else-ve-else-if-yaps.html
		//https://www.yazilimkodlama.com/cplusplus/c-dizi-icindeki-en-buyuk-ve-en-kucuk-degeri-bulma/
		
	void swapSort(int &valueA, int &valueB)
{
	int valueTemp;
	valueTemp = valueA;
	valueA = valueB;
	valueB = valueTemp;
}
