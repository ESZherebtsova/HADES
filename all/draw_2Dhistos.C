#include <TStyle.h>
#include "TMath.h"
#include "TFile.h"
#include "TCanvas.h"
#include <iostream>
#include "TH2F.h"
#include "TChain.h"
#include "TLegend.h"
#include "TLatex.h"

void draw_2Dhistos() {

TChain *tree1=new TChain("tree");
tree1->Add("/lustre/nyx/cbm/users/ogolosov/HADES/treeMaker/output/Nov_23_14_46/tree*.root");
//tree1->Add("/lustre/nyx/cbm/users/ogolosov/HADES/treeMaker/output/Nov_23_14_46/tree_12108160806.root");

TH2F *hEta_vs_Phi_pos=new TH2F("hEta_vs_Phi_pos","",160,0,1.6,628,0,6.28);
TH2F *hEta_vs_Phi_neg=new TH2F("heta_vs_Phi_neg","",160,0,1.6,628,0,6.28);
TH2F *hPt_vs_Phi=new TH2F("hPt_vs_Phi","", 2200,0,2200, 628,0,6.28);
TH2F *hPt_Phi_Scale=new TH2F("hEta_Pt_Scale","",2200,0,2200,628,0,6.28);

	float theta[200];
	float Eta;
	short charge[200];
        short Charge;
        float Phi;
	float phi[200];
	float pt[200];
	float Pt;
	float angle;
	angle=3.14/3;
	Int_t nTracks;	
	Float_t vZ,vX,vY,vChi2;
	Float_t Integral;
        Float_t BinContent;

	tree1->SetBranchAddress("vZ", &vZ);
        tree1->SetBranchAddress("vX", &vX);
        tree1->SetBranchAddress("vY", &vY);
        tree1->SetBranchAddress("vChi2", &vChi2);
	tree1->SetBranchAddress("pt", &pt);
        tree1->SetBranchAddress("charge", &charge);
        tree1->SetBranchAddress("phi", &phi);
	tree1->SetBranchAddress("nTracks", &nTracks);
	tree1->SetBranchAddress("theta", &theta);

	int entry=0;
	while(entry < tree1->GetEntries()) {
                tree1->GetEntry(entry);

	if (vZ>=-60 && vZ<=0 && (pow(vX*vX+vY*vY,0.5)<3) && vChi2>0.5 && vChi2<22) {
	
		
	for (int i=0;i<nTracks;i++) {

		Eta=-TMath::Log(TMath::Tan(theta[i]/2));
		Phi=phi[i];
		Charge=charge[i];
		Pt=pt[i];

		if (Charge>0) { hEta_vs_Phi_pos->Fill(Eta,Phi); }
		if (Charge<0) { hEta_vs_Phi_neg->Fill(Eta,Phi); }

		hPt_vs_Phi->Fill(Pt,Phi);
		


			} //end track loop

		} //end cut event loop

		entry++;

	} //END EVENT LOOP
	

	for (int i=0;i<628;i++) {

		TH1D *projh2X=hPt_vs_Phi->ProjectionX("",i,i,"");
		Integral=projh2X->Integral();

		for (int j=0; j<2200; j++) {
			
		if (Integral!=0) {
	
			BinContent=(hPt_vs_Phi->GetBinContent(j,i))/Integral;
			hPt_Phi_Scale->SetBinContent(j,i,BinContent);
	
			} //end if 
	
		    } //end bin phi loop
	
		} //end bin pt loop

/*
TCanvas *fhMDCtrk_PrimTrk = new TCanvas("fhMDCtrk_PrimTrk");
        fhMDCtrk_PrimTrk ->cd();
        gPad-> SetLogz();
        hMDCtrk_PrimTrk->GetXaxis()->SetTitle("MDC tracks");
        hMDCtrk_PrimTrk->GetYaxis()->SetTitle("Primary Tracks");
        hMDCtrk_PrimTrk->Draw("COLZ");

        fhMDCtrk_PrimTrk->Print("hMDCtrk_PrimTrk.png");
        fhMDCtrk_PrimTrk->SaveAs("hMDCtrk_PrimTrk.C","RECREATE");

TCanvas *fhTOFhit_PrimTrk = new TCanvas("fhTOFhit_PrimTrk");
        fhTOFhit_PrimTrk->cd();
        gPad-> SetLogz();
        hTOFhit_PrimTrk->GetXaxis()->SetTitle("TOF hits");
        hTOFhit_PrimTrk->GetYaxis()->SetTitle("Primary Tracks");
        hTOFhit_PrimTrk->Draw("COLZ");

        fhTOFhit_PrimTrk->Print("hTOFhit_PrimTrk.png");
        fhTOFhit_PrimTrk->SaveAs("hTOFhit_PrimTrk.C","RECREATE");

TCanvas *fhRPChit_PrimTrk = new TCanvas("fhRPChit_PrimTrk");
        fhRPChit_PrimTrk->cd();
        gPad-> SetLogz();
        hRPChit_PrimTrk->GetXaxis()->SetTitle("RPC hits");
        hRPChit_PrimTrk->GetYaxis()->SetTitle("Primary Tracks");
        hRPChit_PrimTrk->Draw("COLZ");

        fhRPChit_PrimTrk->Print("hRPChit_PrimTrk.png");
        fhRPChit_PrimTrk->SaveAs("hRPChit_PrimTrk.C","RECREATE");

*/

TCanvas *fEta_Phi = new TCanvas("fEta_Phi");
        fEta_Phi ->cd();
	gStyle->SetOptStat(0);
        gPad-> SetLogz();
        hEta_vs_Phi_pos->GetXaxis()->SetTitle("#eta");
        hEta_vs_Phi_pos->GetYaxis()->SetTitle("#phi, [rad]");
        hEta_vs_Phi_pos->Draw("COLZ");

	TLatex *t = new TLatex(0.56, 6.59, "Charge of track>0");
	t->Draw();

        fEta_Phi->Print("./pics/Eta_vs_Phi_PosTrkCharge.png");
        fEta_Phi->SaveAs("./pics/Eta_vs_Phi_PosTrkCharge.C","RECREATE");

TCanvas *fEta_Phi2 = new TCanvas("fEta_Phi2");
        fEta_Phi2 ->cd();
	gStyle->SetOptStat(0);
        gPad-> SetLogz();
        hEta_vs_Phi_neg->GetXaxis()->SetTitle("#eta");
        hEta_vs_Phi_neg->GetYaxis()->SetTitle("#phi, [rad]");
        hEta_vs_Phi_neg->Draw("COLZ");

	TLatex *t2 = new TLatex(0.56, 6.59, "Charge of track<0");
        t2->Draw();

        fEta_Phi2->Print("./pics/Eta_vs_Phi_NegTrkCharge.png");
        fEta_Phi2->SaveAs("./pics/Eta_vs_Phi_NegTrkCharge.C","RECREATE");

TCanvas *fhpt_vs_phi = new TCanvas("fhpt_vs_phi");
        fhpt_vs_phi ->cd();
	gStyle->SetOptStat(0);
        gPad-> SetLogz();
        hPt_vs_Phi->GetXaxis()->SetTitle(" p_{T}, [MeV]");
        hPt_vs_Phi->GetYaxis()->SetTitle("#phi, [rad]");
        hPt_vs_Phi->Draw("COLZ");

        fhpt_vs_phi->Print("./pics/Pt_vs_Phi.png");
        fhpt_vs_phi->SaveAs("./pics/Pt_vs_Phi.C","RECREATE");

TCanvas *fhEta_Pt_Scale = new TCanvas("fhEta_Pt_Scale");
        fhEta_Pt_Scale ->cd();
	gStyle->SetOptStat(0);
        gPad-> SetLogz();
        hPt_Phi_Scale->GetXaxis()->SetTitle(" p_{T}, [MeV]");
        hPt_Phi_Scale->GetYaxis()->SetTitle("#phi, [rad]");
        hPt_Phi_Scale->Draw("COLZ");

        fhEta_Pt_Scale->Print("./pics/Pt_vs_Phi_Scale.png");
	fhEta_Pt_Scale->SaveAs("./pics/Pt_vs_Phi_Scale.C","RECREATE");
        

}
