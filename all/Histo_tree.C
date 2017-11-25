#include "TTree.h"
#include <iostream>
#include "TH1F.h"
#include "TH2F.h"
#include "TF1.h"
#include <TNtuple.h>
#include "TFile.h"
#include "TChain.h"
#include "TMath.h"

void Histo_tree () {
TChain *tree1=new TChain("tree");
tree1->Add("/lustre/nyx/cbm/users/ogolosov/HADES/treeMaker/output/Nov_18_1_58/tree*.root");

TFile* TreeFile = new TFile("NTree_AfterKardanCuts.root","RECREATE");
//TNtuple *nt = new TNtuple("nt","nt","N_TOF_hits:N_MDC_hits_ALL_pos:N_MDC_tracks_02_eta_04_pos:N_MDC_tracks_04_eta_06_pos:N_MDC_tracks_06_eta_08_pos:N_MDC_tracks_08_eta_16_pos:N_MDC_hits_ALL_neg:N_MDC_tracks_02_eta_04_neg:N_MDC_tracks_04_eta_06_neg:N_MDC_tracks_06_eta_08_neg:N_MDC_tracks_08_eta_16_neg:N_FW_hits_ALL:N_FW_hits_RING_0:N_FW_hits_RING_1_4:N_FW_hits_RING_5_6:N_FW_hits_RING_7_9:N_FW_charge_ALL:N_FW_charge_RING_0:N_FW_charge_RING_1_4:N_FW_charge_RING_5_6:N_FW_charge_RING_7_9");
TTree *myTree=new TTree("tree","tree");
	
	Short_t N_TOF_hits, N_MDC_hits_ALL_pos, N_MDC_tracks_02_eta_04_pos, N_MDC_tracks_04_eta_06_pos, N_MDC_tracks_06_eta_08_pos; 
Short_t N_MDC_tracks_08_eta_16_pos, N_MDC_hits_ALL_neg, N_MDC_tracks_02_eta_04_neg, N_MDC_tracks_04_eta_06_neg; 
Short_t N_MDC_tracks_06_eta_08_neg, N_MDC_tracks_08_eta_16_neg, N_FW_hits_ALL, N_FW_hits_RING_0, N_FW_hits_RING_1_4;
Short_t N_FW_hits_RING_5_6, N_FW_hits_RING_7_9;
Float_t N_FW_charge_ALL, N_FW_charge_RING_0, N_FW_charge_RING_1_4, N_FW_charge_RING_5_6, N_FW_charge_RING_7_9;
	Short_t N_MDC_tracks_ALL, N_MDC_tracks_02_eta_04_ALL, N_TOF_MDC_hits, N_TOF_MDC_hits_Cut;

	short ModuleNumber;
	Short_t N_MDC_hits_event, counthits=0;
        Short_t nTracks,nTofHitsCut;
	Int_t  nTofHitsCut_;
	Int_t nRpcClustCut,N_RPC_hits;
	Float_t vZ,vX,vY,vChi2;
        Short_t wallChargeTot;
	Int_t  wallChargeTot_;
        Float_t theta[200];
        Float_t Eta;
        Short_t nWallHitsTot;
	Short_t MDChits, MDChits_Cut;
        Short_t nMdcHits[200];
        Int_t MDC_hits_pos, MDC_hits_neg;
	Short_t charge[200];
	Short_t Charge_trk;
	Short_t wallHitRing[200]; 
	Short_t countall=0, count1=0, count2=0, count3=0, count4=0, count5=0, count6=0, count7=0, count8=0, count9=0;
	Int_t trk1, trk2, trk3, trk4, trk5, trk6, trk7, trk8;
	Short_t c1=0, c2=0, c3=0, c4=0, c=0;
	Int_t hits1, hits2, hits3, hits4, hitsAll;
	Short_t ring;
	Float_t hit_beta;
	Int_t Charge_0, Charge_14, Charge_56, Charge_79;
	Short_t wallHitCharge[200];
	Short_t wallHitTime[200];  
        Short_t wallHitDistance[200];
	Float_t VertexX, VertexY, VertexZ, VertexChi2;
	Bool_t  isWallHitOk[200];	
	Short_t wallModuleCharge[305];	
	Short_t wallModuleIndex[200];
	Short_t wallQModule;
	Short_t NumberOfModule;

	tree1->SetBranchAddress("wallModuleIndex", &wallModuleIndex);
	tree1->SetBranchAddress("wallHitTime", &wallHitTime);
//	tree1->SetBranchAddress("N_MDC_hits_event", &N_MDC_hits_event);
	tree1->SetBranchAddress("nRpcClustCut", &nRpcClustCut);
	tree1->SetBranchAddress("wallHitDistance", &wallHitDistance);
        tree1->SetBranchAddress("nTofHitsCut", &nTofHitsCut);
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
	tree1->SetBranchAddress("nTracks", &nTracks);
	 tree1->SetBranchAddress("isWallHitOk", &isWallHitOk);

		myTree->Branch("N_MDC_hits_event", &N_MDC_hits_event, "N_MDC_hits_event/S");
		myTree->Branch("wallModuleCharge", &wallModuleCharge, "wallModuleCharge[305]/S");
		myTree->Branch("VertexX", &VertexX, "VertexX/F");
		myTree->Branch("VertexY", &VertexY, "VertexY/F");
		myTree->Branch("VertexZ", &VertexZ, "VertexZ/F");
		myTree->Branch("VertexChi2", &VertexChi2, "VertexChi2/F");
		myTree->Branch("N_RPC_hits", &N_RPC_hits, "N_RPC_hits/I");
	//	myTree->Branch("N_TOF_MDC_hits_Cut",&N_TOF_MDC_hits_Cut,"N_TOF_MDC_hits_Cut/S");
	//	myTree -> Branch("N_MDC_tracks_ALL",&N_MDC_tracks_ALL,"N_MDC_tracks_ALL/S");
		myTree -> Branch("N_TOF_hits",&N_TOF_hits,"N_TOF_hits/S");
		myTree -> Branch("N_MDC_hits_ALL_pos",&N_MDC_hits_ALL_pos,"N_MDC_hits_ALL_pos/S");
 		myTree -> Branch("N_MDC_tracks_02_eta_04_pos",&N_MDC_tracks_02_eta_04_pos,"N_MDC_tracks_02_eta_04_pos/S");
 		myTree -> Branch("N_MDC_tracks_04_eta_06_pos",&N_MDC_tracks_04_eta_06_pos,"N_MDC_tracks_04_eta_06_pos/S");
		myTree -> Branch("N_MDC_tracks_06_eta_08_pos",&N_MDC_tracks_06_eta_08_pos,"N_MDC_tracks_06_eta_08_pos/S");
		myTree -> Branch("N_MDC_tracks_08_eta_16_pos",&N_MDC_tracks_08_eta_16_pos,"N_MDC_tracks_08_eta_16_pos/S");
		myTree -> Branch("N_MDC_hits_ALL_neg",&N_MDC_hits_ALL_neg,"N_MDC_hits_ALL_neg/S");
 		myTree -> Branch("N_MDC_tracks_02_eta_04_neg",&N_MDC_tracks_02_eta_04_neg,"N_MDC_tracks_02_eta_04_neg/S");
		myTree -> Branch("N_MDC_tracks_04_eta_06_neg",&N_MDC_tracks_04_eta_06_neg,"N_MDC_tracks_04_eta_06_neg/S");
 		myTree -> Branch("N_MDC_tracks_06_eta_08_neg",&N_MDC_tracks_06_eta_08_neg,"N_MDC_tracks_06_eta_08_neg/S");
		myTree -> Branch("N_MDC_tracks_08_eta_16_neg",&N_MDC_tracks_08_eta_16_neg,"N_MDC_tracks_08_eta_16_neg/S");
		myTree -> Branch("N_FW_hits_ALL",&N_FW_hits_ALL,"N_FW_hits_ALL/S");
		myTree -> Branch("N_FW_hits_RING_0",&N_FW_hits_RING_0,"N_FW_hits_RING_0/S");
		myTree -> Branch("N_FW_hits_RING_1_4",&N_FW_hits_RING_1_4,"N_FW_hits_RING_1_4/S");
		myTree -> Branch("N_FW_hits_RING_5_6",&N_FW_hits_RING_5_6,"N_FW_hits_RING_5_6/S");
		myTree -> Branch("N_FW_hits_RING_7_9",&N_FW_hits_RING_7_9,"N_FW_hits_RING_7_9/S");
	//	myTree -> Branch("N_FW_charge_ALL",&N_FW_charge_ALL,"N_FW_charge_ALL/S");
	//	myTree -> Branch("N_FW_charge_RING_0",&N_FW_charge_RING_0,"N_FW_charge_RING_0/S");
		myTree -> Branch("N_FW_charge_ALL",&N_FW_charge_ALL,"N_FW_charge_ALL/F");
		myTree -> Branch("N_FW_charge_RING_0",&N_FW_charge_RING_0,"N_FW_charge_RING_0/F");
		myTree -> Branch("N_FW_charge_RING_1_4",&N_FW_charge_RING_1_4,"N_FW_charge_RING_1_4/F");
		myTree -> Branch("N_FW_charge_RING_5_6",&N_FW_charge_RING_5_6,"N_FW_charge_RING_5_6/F");
		myTree -> Branch("N_FW_charge_RING_7_9",&N_FW_charge_RING_7_9,"N_FW_charge_RING_7_9/F");

	
cout<<" 1 !!"<<endl;
TTree* tree = myTree->CloneTree();

N_MDC_hits_event=0;

int entry=0;
   while(entry <tree1->GetEntries()) {
                tree1->GetEntry(entry);
/*	VertexX=vX;
	VertexY=vY;
	VertexZ=vZ;
	VertexChi2=vChi2;
*/

	//cout<<" entry = "<<entry<<endl;
   if (vZ>-60 && vZ<0 && (pow(vX*vX+vY*vY,0.5)<3) && vChi2>0.5 && vChi2<22) {

	VertexX=vX;
        VertexY=vY;
        VertexZ=vZ;
        VertexChi2=vChi2;


		N_TOF_hits=nTofHitsCut;
		N_RPC_hits=nRpcClustCut;

		counthits=0;
//cout<<" entry = "<<entry<<endl;

 		for (Short_t i=0;i<nTracks;i++) {

		Eta=-TMath::Log(TMath::Tan(theta[i]/2));
		MDChits=nMdcHits[i];
		Charge_trk=charge[i];

//cout<<" hit N track = "<<nMdcHits[i]<<endl;

		counthits+=nMdcHits[i];
//cout<<" count hits = "<<counthits<<endl;
		countall++;
//cout<<" 1 = "<<Eta<<" 2 = "<<Charge_trk<<endl;

	if (Charge_trk>0) N_MDC_hits_ALL_pos=nMdcHits[i];
	if (Charge_trk<0) N_MDC_hits_ALL_neg=nMdcHits[i];


			 // N_MDC_tracks_ALL=nMdcHits[i];
                 if (Eta>0.2 && Eta<0.4 && Charge_trk>0) {	count1++;}
		if (Eta>0.4 && Eta<0.6 && Charge_trk>0) {  count2++;}
		if (Eta>0.6 && Eta<0.8 && Charge_trk>0) {  count3++;}
		if (Eta>0.8 && Eta<1.6 && Charge_trk>0) {  count4++;}
		if (Eta>0.2 && Eta<0.4 && Charge_trk<0) {  count5++;}
		if (Eta>0.4 && Eta<0.6 && Charge_trk<0) {  count6++;}
		if (Eta>0.6 && Eta<0.8 && Charge_trk<0) {  count7++;}
		if (Eta>0.8 && Eta<1.6 && Charge_trk<0) {  count8++;}
		if (Eta>0.2 && Eta<0.4) { count9++; MDChits_Cut=nMdcHits[i]; }

                        } //end tracks loops
//cout<<" 2 !!"<<endl;

		N_MDC_hits_event=counthits;
		counthits=0;
//		cout<<" n mdc = "<<N_MDC_hits_event<<endl;
//		cout<<" MDC hits in track = "<<MDChits<<" number of trk = "<<nTracks<<" N mdc trk in event = "<<N_MDC_hits_event<<endl;

		N_TOF_MDC_hits_Cut=N_TOF_hits+MDChits_Cut;
		N_TOF_MDC_hits=N_TOF_hits+MDChits;
		N_MDC_tracks_ALL=countall;
		countall=0;
		N_MDC_tracks_02_eta_04_ALL=count9;
		count9=0;
		N_MDC_tracks_02_eta_04_pos=count1;
		count1=0;
		N_MDC_tracks_04_eta_06_pos=count2;
                count2=0;
		N_MDC_tracks_06_eta_08_pos =count3;
//f module = "<<NumberOfModule<<" wall hit charge "<<wallHitCharge[j]<<" wallModuleCharge[NumberOfModule] = "<<wallModuleCharge[j][NumberOfModule]<<endl;
                count3=0;
		N_MDC_tracks_08_eta_16_pos=count4;
                count4=0;
		N_MDC_tracks_02_eta_04_neg=count5;
                count5=0;
		N_MDC_tracks_04_eta_06_neg=count6;
                count6=0;
		N_MDC_tracks_06_eta_08_neg=count7;
                count7=0;
		N_MDC_tracks_08_eta_16_neg=count8;
                count8=0;

//cout<<" trk 8 = "<<trk8<<endl;
		N_FW_charge_RING_0=0;
		N_FW_charge_RING_1_4=0;
		N_FW_charge_RING_5_6=0;
		N_FW_charge_RING_7_9=0;
		N_FW_charge_ALL=0;
	//	wallModuleCharge[200][NumberOfModule]=0;

	
		Float_t hit_beta;

		for (Short_t j=0; j<nWallHitsTot; j++) {

		ring=wallHitRing[j];
		N_FW_hits_ALL=c++;
		N_FW_charge_ALL+=wallHitCharge[j];
		NumberOfModule=wallModuleIndex[j];

//cout<<" number of module = "<<NumberOfModule<<" wall hit charge "<<wallHitCharge[j]<<endl;
		if (ring==0) { N_FW_hits_RING_0=c1++;    }
		if (ring>0 && ring<5) {   N_FW_hits_RING_1_4=c2++;  }
		if (ring>4 && ring<7) {   N_FW_hits_RING_5_6=c3++; }
		if (ring>6 && ring<=9) {   N_FW_hits_RING_7_9=c4++;  }

		hit_beta = wallHitDistance[j]/wallHitTime[j]/299.792458;
            if ( (ring<=4            && wallHitCharge[j]>80 && hit_beta>0.84 && hit_beta<1.) ||
                 ((ring==5||ring==6) && wallHitCharge[j]>85 && hit_beta>0.85 && hit_beta<1.) ||
                 (ring>6             && wallHitCharge[j]>86 && hit_beta>0.80 && hit_beta<1.) ) {

		
	//		 wallModuleCharge[j][l]+=wallHitCharge[j];cout<<" number of module = "<<NumberOfModule<<" wall hit charge "<<wallHitCharge[j]<<" wallModuleCharge[NumberOfModule] = "<<wallModuleCharge[j][NumberOfModule]<<endl;


	//		cout<<" number of module = "<<l<<" wall hit charge "<<wallHitCharge[j]<<" wallModuleCharge[NumberOfModule] = "<<wallModuleCharge[j][l]<<endl;	
		



                        if (ring==0) N_FW_charge_RING_0+=wallHitCharge[j];
                        if (ring>0 && ring<5)  N_FW_charge_RING_1_4+=wallHitCharge[j];
                        if (ring>4 && ring<7)  N_FW_charge_RING_5_6+=wallHitCharge[j];
                        if (ring>6 && ring<=9)  N_FW_charge_RING_7_9+=wallHitCharge[j];
                        N_FW_charge_ALL+=wallHitCharge[j];
              	} //end kardan cuts		
								} //end wall hits
		cout<<" second loop"<<endl;					
	

		for (short h=1; h<305; h++) { wallModuleCharge[h]=0; }
	
		for (short k=1; k<305; k++) {
		
			for (short p=0; p<nWallHitsTot; p++) {		
			
			    /* ring=wallHitRing[p];
				isWallHitOk[p] = kFALSE;

		             hit_beta = wallHitDistance[p]/wallHitTime[p]/299.792458;
                             if ( (ring<=4            && wallHitCharge[p]>80 && hit_beta>0.84 && hit_beta<1.) ||
                             ((ring==5||ring==6) && wallHitCharge[p]>85 && hit_beta>0.85 && hit_beta<1.) ||
                             (ring>6             && wallHitCharge[p]>86 && hit_beta>0.80 && hit_beta<1.) ) {


			isWallHitOk[p] = kTRUE;
		*/
// 			if (ModuleNumber==k) { 
				wallModuleCharge[ModuleNumber]+=wallHitCharge[p];
				cout<<"mod = "<<k<<"hit charge "<<wallHitCharge[p]<<"ModuleCharge= "<<wallModuleCharge[ModuleNumber]<<endl;
					// } //end if module nuber

				     // } //end kardan cits case 2

				} // end wall jits loop case 2
				
			} //end ,odule number loop 
		                                                                             

		

						
		N_FW_hits_ALL=c;
		c=0;
		N_FW_hits_RING_0=c1;
		c1=0;
		N_FW_hits_RING_1_4=c2;
		c2=0;
		N_FW_hits_RING_5_6=c3;
		c3=0;
		N_FW_hits_RING_7_9=c4;
		c4=0;
/*
		hit_beta = wallHitDistance[j]/wallHitTime[j]/299.792458;
            if ( (ring<=4            && wallHitCharge[j]>80 && hit_beta>0.84 && hit_beta<1.) ||
                 ((ring==5||ring==6) && wallHitCharge[j]>85 && hit_beta>0.85 && hit_beta<1.) ||
                 (ring>6             && wallHitCharge[j]>86 && hit_beta>0.80 && hit_beta<1.) ) {


			if (ring==0) N_FW_charge_RING_0+=wallHitCharge[j];
			if (ring>0 && ring<5)  N_FW_charge_RING_1_4+=wallHitCharge[j];
			if (ring>4 && ring<7)  N_FW_charge_RING_5_6+=wallHitCharge[j]; 
			if (ring>6 && ring<=9)  N_FW_charge_RING_7_9+=wallHitCharge[j];
			N_FW_charge_ALL+=wallHitCharge[j];
													}*/
/*
Float_t v[21]; Int_t k=0;
v[k++]=nTofHitsCut_;
v[k++]=MDC_hits_pos;
v[k++]=trk1;
v[k++]=trk2;
v[k++]=trk3;
v[k++]=trk4;cout<<" number of module = "<<NumberOfModule<<" wall hit charge "<<wallHitCharge[j]<<" wallModuleCharge[NumberOfModule] = "<<wallModuleCharge[j][NumberOfModule]<<endl;
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
*/
//cout<<" Fill" <<endl;
//tree->Fill();
//cout<<" entry = "<<entry<<endl;
tree->Fill();
} // end event cut loop
	//	tree->Fill();

		entry++;

}
cout<<"End"<<endl;					
TreeFile->cd();

tree->Write();
TreeFile->Close();
cout<<"End Tree"<<endl;
}
