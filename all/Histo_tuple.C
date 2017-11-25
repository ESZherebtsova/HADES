#include "TTree.h"
#include <iostream>
#include "TH1F.h"
#include "TH2F.h"
#include "TF1.h"
#include <TNtuple.h>
#include "TFile.h"
#include "TChain.h"

void Histo_tuple () {
TChain *tree1=new TChain("tree");
tree1->Add("tree_121081*.root");

TFile* TreeFile = new TFile("NTuple.root","RECREATE");
TNtuple *nt = new TNtuple("nt","nt","N_TOF_hits:N_MDC_hits_ALL_pos:N_MDC_tracks_02_eta_04_pos:N_MDC_tracks_04_eta_06_pos:N_MDC_tracks_06_eta_08_pos:N_MDC_tracks_08_eta_16_pos:N_MDC_hits_ALL_neg:N_MDC_tracks_02_eta_04_neg:N_MDC_tracks_04_eta_06_neg:N_MDC_tracks_06_eta_08_neg:N_MDC_tracks_08_eta_16_neg:N_FW_hits_ALL:N_FW_hits_RING_0:N_FW_hits_RING_1_4:N_FW_hits_RING_5_6:N_FW_hits_RING_7_9:N_FW_charge_ALL:N_FW_charge_RING_0:N_FW_charge_RING_1_4:N_FW_charge_RING_5_6:N_FW_charge_RING_7_9");
//TTree *tree=new TTree("tree","tree");


        Short_t nTracks,nTofHitsCut;
	Int_t  nTofHitsCut_;
        Float_t vZ,vX,vY,vChi2;
        Short_t wallChargeTot;
	Int_t  wallChargeTot_;
        Float_t theta[200];
        Float_t Eta;
        Short_t nWallHitsTot;
        Short_t nMdcHits[200];
        Int_t MDC_hits_pos, MDC_hits_neg;
	Short_t charge[200];
	Short_t Charge_trk;
	Short_t wallHitRing[200]; 
	Short_t count1=0, count2=0, count3=0, count4=0, count5=0, count6=0, count7=0, count8=0;
	Int_t trk1, trk2, trk3, trk4, trk5, trk6, trk7, trk8;
	Short_t c1, c2, c3, c4, c;
	Int_t hits1, hits2, hits3, hits4, hitsAll;
	Short_t ring;
	Int_t Charge_0, Charge_14, Charge_56, Charge_79;
	Short_t wallHitCharge[200];
        tree1->SetBranchAddress("nTofHitsCut", &nTofHitsCut);
        tree1->SetBranchAddress("nTracks", &nTracks);
        tree1->SetBranchAddress("vZ", &vZ);
        tree1->SetBranchAddress("vX", &vX);
        tree1->SetBranchAddress("vY", &vY);
        tree1->SetBranchAddress("wallChargeTot", &wallChargeTot);
        tree1->SetBranchAddress("vChi2", &vChi2);
        tree1->SetBranchAddress("theta", &theta);
        tree1->SetBranchAddress("nWallHitsTot", &nWallHitsTot);
        tree1->SetBranchAddress("nMdcHits", &nMdcHits);
	tree1->SetBranchAddress("charge", &charge);
	tree1->SetBranchAddress("wallHitRing", &wallHitRing);
	tree1->SetBranchAddress("wallHitCharge", &wallHitCharge);


cout<<" 1 !!"<<endl;

int entry=0;
   while(entry < tree1->GetEntries()) {
                tree1->GetEntry(entry);
   if (vZ>-60 && vZ<0 && (pow(vX*vX+vY*vY,0.5)<3) && vChi2>0.5 && vChi2<22) {

		nTofHitsCut_=(int)nTofHitsCut;
		wallChargeTot_=(int)wallChargeTot;
 		for (Short_t i=0;i<nTracks;i++) {

		Eta=theta[i];
//		MDChits=nMdcHits[i];
		Charge_trk=charge[i];

//cout<<" 1 = "<<Eta<<" 2 = "<<Charge_trk<<endl;

	if (Charge_trk>0) MDC_hits_pos=(int)nMdcHits[i];
	if (Charge_trk<0) MDC_hits_neg=(int)nMdcHits[i];

                 if (Eta>0.2 && Eta<0.4 && Charge_trk>0) {	count1++;}
		if (Eta>0.4 && Eta<0.6 && Charge_trk>0) {  count2++;}
		if (Eta>0.6 && Eta<0.8 && Charge_trk>0) {  count3++;}
		if (Eta>0.8 && Eta<1.6 && Charge_trk>0) {  count4++;}
		if (Eta>0.2 && Eta<0.4 && Charge_trk<0) {  count5++;}
		if (Eta>0.4 && Eta<0.6 && Charge_trk<0) {  count6++;}
		if (Eta>0.6 && Eta<0.8 && Charge_trk<0) {  count7++;}
		if (Eta>0.8 && Eta<1.6 && Charge_trk<0) {  count8++;}

                        }
//cout<<" 2 !!"<<endl;

		trk1=(int)count1;
		count1=0;
		trk2=(int)count2;
                count2=0;
		trk3=(int)count3;
                count3=0;
		trk4=(int)count4;
                count4=0;
		trk5=(int)count5;
                count5=0;
		trk6=(int)count6;
                count6=0;
		trk7=(int)count7;
                count7=0;
		trk8=(int)count8;
                count8=0;

//cout<<" trk 8 = "<<trk8<<endl;
		Charge_0=0;
		Charge_14=0;
		Charge_56=0;
		Charge_79=0;

		for (Short_t j=0; j<nWallHitsTot; j++) {

		ring=wallHitRing[j];
		hitsAll=c++;
		if (ring==0) { hits1=c1++;  Charge_0+=(int)wallHitCharge[j];   }
		if (ring>0 && ring<5) {   hits2=c2++; Charge_14+=(int)wallHitCharge[j];  }
		if (ring>4 && ring<7) {   hits3=c3++; Charge_56+=(int)wallHitCharge[j];  }
		if (ring>6 && ring<=9) {   hits4=c4++; Charge_79+=(int)wallHitCharge[j];  }
							}
		hitsAll=(int)c;
		c=0;
		hits1=(int)c1;
		c1=0;
		hits2=(int)c2;
		c2=0;
		hits3=(int)c3;
		c3=0;
		hits4=(int)c4;
		c4=0;

Float_t v[21]; Int_t k=0;
v[k++]=nTofHitsCut_;
v[k++]=MDC_hits_pos;
v[k++]=trk1;
v[k++]=trk2;
v[k++]=trk3;
v[k++]=trk4;
v[k++]=MDC_hits_neg;
v[k++]=trk5;
v[k++]=trk6;
v[k++]=trk7;
v[k++]=trk8;
v[k++]=hitsAll;
v[k++]=hits1;
v[k++]=hits2;
v[k++]=hits3;
v[k++]=hits4;
v[k++]=wallChargeTot_;
v[k++]=Charge_0;
v[k++]=Charge_14;
v[k++]=Charge_56;
v[k++]=Charge_79;

//cout<<" Fill" <<endl;
nt->Fill(v);
//cout<<" entry = "<<entry<<endl;
}
		entry++;

}
cout<<"End"<<endl;					
TreeFile->Write();
TreeFile->Close();
cout<<"End Tree"<<endl;
}
