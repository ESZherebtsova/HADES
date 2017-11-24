#include "TMath.h"
#include <TH1.h>
#include <TF1.h>
#include "TFile.h"
#include "TFrame.h"
#include "TCanvas.h"
#include "TTree.h"
#include <iostream>
#include "TH1F.h"
#include "TH2F.h"
#include "TF1.h"
#include "TChain.h"
#include "TTree.h"
#include "TLegend.h"

void TreeForFWchargeInModules () {

TChain *tree1=new TChain("tree");
tree1->Add("/lustre/nyx/cbm/users/ogolosov/HADES/treeMaker/output/Nov_23_14_46/tree_1210816*.root");
//tree1->Add("/lustre/nyx/cbm/users/ogolosov/HADES/treeMaker/output/Nov_22_21_41/tree*.root");

	TH2F *FWcharge_vs_ModIndex=new TH2F("FWcharge_vs_ModIndex","",2000,0,2000,304,1,304);

	TFile* TreeFile = new TFile("NTree_FWchargeInModules.root","RECREATE");

	 Bool_t cuts[8];
        Float_t vZ,vX,vY,vChi2;
	Float_t wallChargeTot_mod[305];
	Short_t nWallHitsTot;

//	tree1->SetBranchAddress("nWallHitsTot", &nWallHitsTot);
        tree1->SetBranchAddress("vZ", &vZ);
        tree1->SetBranchAddress("vX", &vX);
        tree1->SetBranchAddress("vY", &vY);
        tree1->SetBranchAddress("vChi2", &vChi2);
	tree1->SetBranchAddress("cuts", &cuts);
	tree1->SetBranchAddress("wallChargeTot_mod", &wallChargeTot_mod);

	TH1F *hFWcharge[304];

        for (int i=0; i<304;i++)
                {
                  hFWcharge[i]=new TH1F("","",1500,0,1500);
                }


	 int entry=0;
        while(entry < tree1->GetEntries()) {
                tree1->GetEntry(entry);

                if (cuts[0] && cuts[1] && cuts[2] && cuts[3] && cuts[4] && cuts[5] && cuts[6] && cuts[7] &&  vZ>=-60 && vZ<=0 && (pow(vX*vX+vY*vY,0.5)<3) && vChi2>0.5 && vChi2<22) {

		for (int i=1; i<=304; i++) {		
		
			hFWcharge[i-1]->Fill(wallChargeTot_mod[i]);
			FWcharge_vs_ModIndex->Fill(wallChargeTot_mod[i],i);

			} //end loop for histos


		} //end cut event
		
		 entry++;
	
	} //end event loop

TreeFile->cd();
/*for (int i=0; i<304; i++) {
	
	hFWcharge[i]->Write();
	
}*/
FWcharge_vs_ModIndex->Write();
TreeFile->Close();

TCanvas *c = new TCanvas("c");
        c->cd();
        gPad-> SetLogz();

	FWcharge_vs_ModIndex->GetXaxis()->SetTitle("FW charge, [GeV]");
	FWcharge_vs_ModIndex->GetYaxis()->SetTitle("Module Index");
	FWcharge_vs_ModIndex->Draw("colz");

	c->Print("FWcharge_vs_ModIndex.png");
	c->SaveAs("FWcharge_vs_ModIndex.C");	



}
