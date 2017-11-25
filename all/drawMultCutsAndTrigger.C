#include "TMath.h"
#include "TFile.h"
#include "TCanvas.h"
#include <iostream>
#include "TH1F.h"
#include "TH2F.h"
#include "TChain.h"
#include "TLegend.h"

void drawMultCutsAndTrigger () {

TChain *tree1=new TChain("tree");
tree1->Add("/lustre/nyx/hades/user/ezherebt/treeMaker/output/Nov_23_14_46/tree*.root");
//tree1->Add("/lustre/nyx/hades/user/ezherebt/treeMaker/output/Nov_23_14_46/tree_12108160806.root");

	//Histo with different standard event cuts

	TH1F *FW_Rejected=new TH1F("FW_Rejected", "", 1500,0,15000);
	TH1F *FW_All=new TH1F("FW_All", "", 1500,0,15000);
	TH1F *FW_Selected=new TH1F("FW_Selected", "FW_Selected", 1500,0,15000);
	TH1F *FW=new TH1F("FW","",150,0,15000);

	TH1F *hTracks_Rejected=new TH1F("hTracks_Rejected", "", 120,0,120);
	TH1F *hTracks_Selected=new TH1F("hTracks_Selected", "", 120,0,120);

	TH1F *MultTOF_Selected=new TH1F("MultTOF_Selected", "MultTOF_Selected", 120,0,120);
	TH1F *MultTOF_Rejected=new TH1F("MultTOF_Rejected", "MultTOF_Rejected", 120,0,120);
	TH1F *MultTOF_All=new TH1F("MultTOF_All", "", 120,0,120);

	TH1F *MultRPC_All=new TH1F("MultRPC_All", "", 300,0,300);
	TH1F *MultRPC_Rejected=new TH1F("MultRPC_Rejected", "MultRPC_Rejected", 300,0,300);
	TH1F *MultRPC_Selected=new TH1F("MultRPC_Selected", "MultRPC_Selected", 300,0,300);

	TH1F *hPrimaryTracks_Rejected=new TH1F("hPrimaryTracks_Rejected", "hPrimaryTracks_Rejected", 120,0,120);
	 TH1F *hPrimaryTracks_Selected=new TH1F("hPrimaryTracks_Selected", "hPrimaryTracks_Selected", 120,0,120);
	TH1F *hPrimaryTracks_All=new TH1F("hPrimaryTracks_All","hPrimaryTracks_All",120,0,120);

	TH1F *hSumTofRpcHits=new TH1F("hSumTofRpcHits","",300,0,300);
	TH1F *hTracks=new TH1F("hTracks", "", 120,0,120);
	TH1F *hPrimaryTracks=new TH1F("hPrimaryTracks", "hPrimaryTracks",120,0,120);

	TH1F *hTracks_All=new TH1F("hTracks_All", "", 120,0,120);
	TH1F *hTracks_Cut1=new TH1F("hTracks_Cut1", "", 120,0,120);
	TH1F *hTracks_Cut2=new TH1F("hTracks_Cut2", "", 120,0,120);
	TH1F *hTracks_Cut3=new TH1F("hTracks_Cut3", "", 120,0,120);
	TH1F *hTracks_Cut4=new TH1F("hTracks_Cut4", "", 120,0,120);
	TH1F *hTracks_Cut5=new TH1F("hTracks_Cut5", "", 120,0,120);
	TH1F *hTracks_Cut6=new TH1F("hTracks_Cut6", "", 120,0,120);
	TH1F *hTracks_Cut7=new TH1F("hTracks_Cut7", "", 120,0,120);
	TH1F *hTracks_Cut8=new TH1F("hTracks_Cut8", "", 120,0,120);

        TH1F *MultTOF_Cut1=new TH1F("MultTOF_Cut1", "", 120,0,120);
        TH1F *MultTOF_Cut2=new TH1F("MultTOF_Cut2", "", 120,0,120);
        TH1F *MultTOF_Cut3=new TH1F("MultTOF_Cut3", "", 120,0,120);
        TH1F *MultTOF_Cut4=new TH1F("MultTOF_Cut4", "", 120,0,120);
        TH1F *MultTOF_Cut5=new TH1F("MultTOF_Cut5", "", 120,0,120);
        TH1F *MultTOF_Cut6=new TH1F("MultTOF_Cut6", "", 120,0,120);
        TH1F *MultTOF_Cut7=new TH1F("MultTOF_Cut7", "", 120,0,120);
        TH1F *MultTOF_Cut8=new TH1F("MultTOF_Cut8", "", 120,0,120);

	//2D Histos 
	TH2F *hMDCtrk_PrimTrk=new TH2F("hMDCtrk_PrimTrk","",120,0,120,120,0,120);
	TH2F *hTOFhit_PrimTrk=new TH2F("hTOFhit_PrimTrk","",120,0,120,120,0,120);
	TH2F *hRPChit_PrimTrk=new TH2F("hRPChit_PrimTrk","",300,0,300,120,0,120);
	TH2F *hTOFRPChit_PrimTrk=new TH2F("hTOFRPChit_PrimTrk","",120,0,120, 300,0,300);
	TH2F *hTOFRPChit_SelectTrk=new TH2F("hTOFRPChit_SelectTrk","",120,0,120, 300,0,300);
	TH2F *hTofRpcHits_FWcharge=new TH2F("hTofRpcHits_FWcharge","",300,0,300,1500,0,15000);
        TH2F *hTofRpcHits_FWhits=new TH2F("hTofRpcHits_FWhits", "", 300,0,300,140,0,140);


	//Histo with different type of trigger
	TH1F *hTracks_PT2Trigger=new TH1F("hTracks_PT2Trigger", "", 120,0,120);
	TH1F *hTracks_PT3Trigger=new TH1F("hTracks_PT3Trigger", "", 120,0,120);
	TH1F *hTracks_PT23Trigger=new TH1F("hTracks_PT23Trigger", "", 120,0,120);
	TH1F *hPrimaryTracks_PT2Trigger=new TH1F("hPrimaryTracks_PT2Trigger", "", 120,0,120);
        TH1F *hPrimaryTracks_PT3Trigger=new TH1F("hPrimaryTracks_PT3Trigger", "", 120,0,120);
        TH1F *hTofHits_PT2Trigger=new TH1F("hTofHits_PT2Trigger","",160,0,160);
	TH1F *hTofHits_PT3Trigger=new TH1F("hTofHits_PT3Trigger","",160,0,160);
	TH1F *hRpcHits_PT2Trigger=new TH1F("hRpcHits_PT2Trigger","",160,0,160);
        TH1F *hRpcHits_PT3Trigger=new TH1F("hRpcHits_PT3Trigger","",160,0,160);
	

	const Int_t nTriggers = 4;
	Bool_t trigInd[nTriggers];
	short nTracks;
	const Short_t nCuts = 8; 
	Int_t nRpcClustCut;
	Int_t nTofHitsCut;
	Int_t primaryTracks;
	Float_t wallChargeTot;
	Bool_t cuts[nCuts];
	Float_t vZ,vX,vY,vChi2;
	Int_t SumTofRpcHits;
	Int_t selectedTracks;
	short nWallHitsTot;	

	Float_t rToBeam[200];
	Float_t zToBeam[200];
	short count;
	short trknumber;
	Float_t DCAxy, DCAz;

	tree1->SetBranchAddress("rToBeam", &rToBeam);
	tree1->SetBranchAddress("zToBeam", &zToBeam);
	tree1->SetBranchAddress("nWallHitsTot", &nWallHitsTot);
	tree1->SetBranchAddress("selectedTracks", &selectedTracks);

	tree1->SetBranchAddress("vZ", &vZ);
        tree1->SetBranchAddress("vX", &vX);
        tree1->SetBranchAddress("vY", &vY);
	tree1->SetBranchAddress("vChi2", &vChi2);
	tree1->SetBranchAddress("nTracks", &nTracks);
	tree1->SetBranchAddress("wallChargeTot", &wallChargeTot);
	tree1->SetBranchAddress("nRpcClustCut", &nRpcClustCut);
	tree1->SetBranchAddress("nTofHitsCut", &nTofHitsCut);
	tree1->SetBranchAddress("primaryTracks", &primaryTracks);
	tree1->SetBranchAddress("cuts", &cuts);
	tree1->SetBranchAddress("trigInd", &trigInd);	

	int entry=0;
        while(entry < tree1->GetEntries()) {
                tree1->GetEntry(entry);

		SumTofRpcHits=nTofHitsCut+nRpcClustCut;		

		if (vZ>=-60 && vZ<=0 && (pow(vX*vX+vY*vY,0.5)<3) && vChi2>0.5 && vChi2<22) {

			hTracks_All->Fill(nTracks);
			MultRPC_All->Fill(nRpcClustCut);
			MultTOF_All->Fill(nTofHitsCut);			
			FW_All->Fill(wallChargeTot);		
			 hPrimaryTracks_All->Fill(primaryTracks);

		if (cuts[0] && cuts[1] && cuts[2] && cuts[3] && cuts[4] && cuts[5] && cuts[6] && cuts[7]) {
	
			count=0;
			for (short i=0;i<nTracks;i++) {

			DCAxy=rToBeam[i];
			DCAz=zToBeam[i];
			
			if (DCAxy<10 && DCAz<10) {

				count++;    

				} 
			trknumber=count;
			

			}
		
			hTracks->Fill(trknumber);
                        hPrimaryTracks->Fill(primaryTracks);
			FW->Fill(wallChargeTot);
			FW_Selected->Fill(wallChargeTot);
			hTracks_Selected->Fill(nTracks);
			MultTOF_Selected->Fill(nTofHitsCut);
			MultRPC_Selected->Fill(nRpcClustCut);
			hPrimaryTracks_Selected->Fill(primaryTracks);
			hSumTofRpcHits->Fill(SumTofRpcHits);
			hMDCtrk_PrimTrk->Fill(nTracks, primaryTracks);
                	hTOFhit_PrimTrk->Fill(nTofHitsCut, primaryTracks);
                	hRPChit_PrimTrk->Fill(nRpcClustCut, primaryTracks);			
			hTOFRPChit_PrimTrk->Fill(primaryTracks, SumTofRpcHits);
			hTOFRPChit_SelectTrk->Fill(selectedTracks, SumTofRpcHits);
			hTofRpcHits_FWcharge->Fill(SumTofRpcHits, wallChargeTot);
			hTofRpcHits_FWhits->Fill(SumTofRpcHits, nWallHitsTot);
		
			hTracks_PT3Trigger->Fill(nTracks);
                        hPrimaryTracks_PT3Trigger->Fill(primaryTracks);
                        hTofHits_PT3Trigger->Fill(nTofHitsCut);
                        hRpcHits_PT3Trigger->Fill(nRpcClustCut);
			}
		else if (!(cuts[0]) || !(cuts[1]) || !(cuts[2]) || !(cuts[3]) ||  !(cuts[4]) || !(cuts[5]) || !(cuts[6]) || !(cuts[7])) {

			FW_Rejected->Fill(wallChargeTot);
                	hTracks_Rejected->Fill(nTracks);
                	MultTOF_Rejected->Fill(nTofHitsCut);
             	        MultRPC_Rejected->Fill(nRpcClustCut);
               	        hPrimaryTracks_Rejected->Fill(primaryTracks);

		/*	if (trigInd[1]) {
                        hTracks_PT2Trigger->Fill(nTracks);
                        hPrimaryTracks_PT2Trigger->Fill(primaryTracks);
                        hTofHits_PT2Trigger->Fill(nTofHitsCut);
                        hRpcHits_PT2Trigger->Fill(nRpcClustCut);
                                 }
                if (trigInd[2]) {
                        hTracks_PT3Trigger->Fill(nTracks);
                        hPrimaryTracks_PT3Trigger->Fill(primaryTracks);
                        hTofHits_PT3Trigger->Fill(nTofHitsCut);
                        hRpcHits_PT3Trigger->Fill(nRpcClustCut);
                                }

		if (trigInd[1] ||  trigInd[2]) { hTracks_PT23Trigger->Fill(nTracks); }
		*/
			} //end else for cuts

		if (!(cuts[0]) && cuts[1] && cuts[2] && cuts[3] && cuts[4] && cuts[5] && cuts[6] && cuts[7]) {
			hTracks_Cut1->Fill(nTracks);
			MultTOF_Cut1->Fill(nTofHitsCut);

			if (trigInd[1]) {
                        hTracks_PT2Trigger->Fill(nTracks);
                        hPrimaryTracks_PT2Trigger->Fill(primaryTracks);
                        hTofHits_PT2Trigger->Fill(nTofHitsCut);
                        hRpcHits_PT2Trigger->Fill(nRpcClustCut);
                                 }
			
			}
		if (cuts[0] && !(cuts[1]) && cuts[2] && cuts[3] && cuts[4] && cuts[5] && cuts[6] && cuts[7]) {	
			 hTracks_Cut2->Fill(nTracks);
			MultTOF_Cut2->Fill(nTofHitsCut);
			}
		 if (cuts[0] && cuts[1] && !(cuts[2]) && cuts[3] && cuts[4] && cuts[5] && cuts[6] && cuts[7]) {
                         hTracks_Cut3->Fill(nTracks);
			MultTOF_Cut3->Fill(nTofHitsCut);
                        }
		 if (cuts[0] && cuts[1] && cuts[2] && !(cuts[3]) && cuts[4] && cuts[5] && cuts[6] && cuts[7]) {
                         hTracks_Cut4->Fill(nTracks);
			MultTOF_Cut4->Fill(nTofHitsCut);
                        }
		 if (cuts[0] && cuts[1] && cuts[2] && cuts[3] && !(cuts[4]) && cuts[5] && cuts[6] && cuts[7]) {
                         hTracks_Cut5->Fill(nTracks);
			MultTOF_Cut5->Fill(nTofHitsCut);
                        }
		 if (cuts[0] && cuts[1] && cuts[2] && cuts[3] && cuts[4] && !(cuts[5]) && cuts[6] && cuts[7]) {
                         hTracks_Cut6->Fill(nTracks);
			MultTOF_Cut6->Fill(nTofHitsCut);
                        }
		 if (cuts[0] && cuts[1] && cuts[2] && cuts[3] && cuts[4] && cuts[5] && !(cuts[6]) && cuts[7]) {
                         hTracks_Cut7->Fill(nTracks);
			MultTOF_Cut7->Fill(nTofHitsCut);
                        }
		 if (cuts[0] && cuts[1] && cuts[2] && cuts[3] && cuts[4] && cuts[5] && cuts[6] && !(cuts[7])) {
                         hTracks_Cut8->Fill(nTracks);
			MultTOF_Cut8->Fill(nTofHitsCut);
                        }
		} //end event cuts 
		 entry++;
	} //end event loop
	
TFile *file1 = new TFile("Tracks.root","RECREATE");
file1->cd();
hTracks->Write();
hPrimaryTracks->Write();
FW_Selected->Write();
file1->Close();

/*
TFile *file = new TFile("Histos_MultCutsvsTriggers.root", "RECREATE");
	file->cd();
	hTracks_Selected->Write();
	hTracks_Rejected->Write();
	hTracks_All->Write();
	MultTOF_Selected->Write();
	MultTOF_Rejected->Write();
	MultTOF_All->Write();
	hPrimaryTracks_Selected->Write();
	hPrimaryTracks_All->Write();
	hPrimaryTracks_Rejected->Write();
	FW_Selected->Write();
	FW_Rejected->Write();
	FW_All->Write();
	hTracks_Cut1->Write();
	hTracks_Cut2->Write();
	hTracks_Cut3->Write();
	hTracks_Cut4->Write();
	hTracks_Cut5->Write();
	hTracks_Cut6->Write();
	hTracks_Cut7->Write();
	hTracks_Cut8->Write();	
	MultTOF_Cut1->Write();
	MultTOF_Cut2->Write();
	MultTOF_Cut3->Write();
	MultTOF_Cut4->Write();
	MultTOF_Cut5->Write();
	MultTOF_Cut6->Write();
	MultTOF_Cut7->Write();
	MultTOF_Cut8->Write();
	hSumTofRpcHits->Write();
	hTOFRPChit_PrimTrk->Write();
	hTOFRPChit_SelectTrk->Write();
	hTofRpcHits_FWcharge->Write();
	hTofRpcHits_FWhits->Write();
	hMDCtrk_PrimTrk->Write();
	hTOFhit_PrimTrk->Write();
	hRPChit_PrimTrk->Write();
	hTracks_PT2Trigger->Write();
	hTracks_PT3Trigger->Write();
	hTracks_PT23Trigger->Write();
	hTofHits_PT2Trigger->Write();
	hTofHits_PT3Trigger->Write();
	hPrimaryTracks_PT2Trigger->Write();
	hPrimaryTracks_PT3Trigger->Write();
	hRpcHits_PT2Trigger->Write();
	hRpcHits_PT3Trigger->Write();
	file->Close();

	char tr[50];
	char name01[50]={"Selected/All Events"};
	char name02[50]={"Rejected/All Events"};
	char name1[250]={"Selected Events"};
	char name2[250]={"Rejected Events"};
	char name3[250]={"All Events"};
	char name4[250]={"Rejected by kGoodTRIGGER"};
	char name5[250]={"Rejected by vertexClust"};
	char name6[250]={"Rejected by vertexCand"};
	char name7[250]={"Rejected by goodSTART"};
	char name8[250]={"Rejected by noPileUpSTART"};
	char name9[250]={"Rejected by noVETO"};
	char name10[250]={"Rejected by goodSTARTVETO"};
	char name11[250]={"Rejected by goodSTARTMETA"};
	char nametr1[50]={"Trigger PT23"};
	char nametr2[50]={"Trigger PT2"};
	char nametr3[50]={"Trigger PT3"};

TCanvas *c = new TCanvas("c");
        c->cd();
        gPad-> SetLogy();
        FW_Selected->SetLineColor(2);
        FW_Rejected->SetLineColor(4);
	FW_All->SetLineColor(3);
        FW_Rejected->GetXaxis()->SetTitle("Q_{FW}, [GeV]");
        FW_Rejected->GetYaxis()->SetTitle("N_{events}");
        FW_Rejected->Draw();
        FW_Selected->Draw("same");
	FW_All->Draw("same");

        TLegend *leg1 = new TLegend(0.2, 0.15, 0.6, 0.4);
        leg1->SetFillColor(0);
        leg1->SetBorderSize(0);
        leg1->SetTextSize(0.03);
        leg1->SetTextFont(42);
        sprintf(tr, "%s", name1);
        leg1->AddEntry(FW_Selected, tr, "l");
        sprintf(tr, "%s", name2);
        leg1->AddEntry(FW_Rejected, tr, "l");
	sprintf(tr, "%s", name3);
        leg1->AddEntry(FW_All, tr, "l");
        leg1->Draw();

        c->Print("./pics/FWchargeWithCuts.png");
        c->SaveAs("./pics/FWChargeWithCuts.C","RECREATE");

TCanvas *c0 = new TCanvas("c0");
        c0->cd();
        gPad-> SetLogy();
//	hTracks_PT23Trigger->SetLineColor(2);
	hTracks_PT2Trigger->SetLineColor(4);
	hTracks_PT3Trigger->SetLineColor(3);
	hTracks_PT3Trigger->GetXaxis()->SetTitle("MDC tracks");
	hTracks_PT3Trigger->GetYaxis()->SetTitle("N_{events}");

//	hTracks_PT23Trigger->Draw();
	hTracks_PT3Trigger->Draw("same");
	hTracks_PT2Trigger->Draw("same");

	TLegend *leg0 = new TLegend(0.2, 0.15, 0.6, 0.4);
        leg0->SetFillColor(0);
        leg0->SetBorderSize(0);
        leg0->SetTextSize(0.03);
        leg0->SetTextFont(42);
  //      sprintf(tr, "%s", nametr1);
    //  leg0->AddEntry(hTracks_PT23Trigger, tr, "l");
	sprintf(tr, "%s", nametr2);
        leg0->AddEntry(hTracks_PT2Trigger, tr, "l");
	sprintf(tr, "%s", nametr3);
        leg0->AddEntry(hTracks_PT3Trigger, tr, "l");
	
	leg0->Draw();
        c0->Print("./pics/hTracks_DiffTrigger.png");
        c0->SaveAs("./pics/hTracks_DiffTrigger.C","RECREATE");


TCanvas *c01 = new TCanvas("c01");
        c01->cd();
        gPad-> SetLogy();
//      hTracks_PT23Trigger->SetLineColor(2);
        hPrimaryTracks_PT2Trigger->SetLineColor(4);
        hPrimaryTracks_PT3Trigger->SetLineColor(3);
        hPrimaryTracks_PT3Trigger->GetXaxis()->SetTitle("primary tracks");
        hPrimaryTracks_PT3Trigger->GetYaxis()->SetTitle("N_{events}");

//      hTracks_PT23Trigger->Draw();
        hPrimaryTracks_PT3Trigger->Draw();
        hPrimaryTracks_PT2Trigger->Draw("same");

        TLegend *leg01 = new TLegend(0.2, 0.15, 0.6, 0.4);
        leg01->SetFillColor(0);
        leg01->SetBorderSize(0);
        leg01->SetTextSize(0.03);
        leg01->SetTextFont(42);
//        sprintf(tr, "%s", nametr1);
//      leg01->AddEntry(hPrimaryTracks_PT23Trigger, tr, "l");
        sprintf(tr, "%s", nametr2);
        leg01->AddEntry(hPrimaryTracks_PT2Trigger, tr, "l");
        sprintf(tr, "%s", nametr3);
        leg01->AddEntry(hPrimaryTracks_PT3Trigger, tr, "l");

        leg01->Draw();
        c01->Print("./pics/hPrimaryTracks_DiffTrigger.png");
        c01->SaveAs("./pics/hPrimaryTracks_DiffTrigger.C","RECREATE");

TCanvas *c02 = new TCanvas("c02");
        c02->cd();
        gPad-> SetLogy();
//      hTofHits_PT23Trigger->SetLineColor(2);
        hTofHits_PT2Trigger->SetLineColor(4);
        hTofHits_PT3Trigger->SetLineColor(3);
        hTofHits_PT3Trigger->GetXaxis()->SetTitle("TOF hits tracks");
        hTofHits_PT3Trigger->GetYaxis()->SetTitle("N_{events}");

//      hTracks_PT23Trigger->Draw();
        hTofHits_PT3Trigger->Draw();
        hTofHits_PT2Trigger->Draw("same");

        TLegend *leg02 = new TLegend(0.2, 0.15, 0.6, 0.4);
        leg02->SetFillColor(0);
        leg02->SetBorderSize(0);
        leg02->SetTextSize(0.03);
        leg02->SetTextFont(42);
//        sprintf(tr, "%s", nametr1);
//      leg02->AddEntry(hPrimaryTracks_PT23Trigger, tr, "l");
        sprintf(tr, "%s", nametr2);
        leg02->AddEntry(hTofHits_PT2Trigger, tr, "l");
        sprintf(tr, "%s", nametr3);
        leg02->AddEntry(hTofHits_PT3Trigger, tr, "l");

        leg02->Draw();
        c02->Print("./pics/hTofHits_DiffTrigger.png");
        c02->SaveAs("./pics/hTofHits_DiffTrigger.C","RECREATE");

TCanvas *c03 = new TCanvas("c03");
        c03->cd();
        gPad-> SetLogy();
        MultTOF_Cut1->GetXaxis()->SetTitle("TOF hits");
        MultTOF_Cut1->GetYaxis()->SetTitle("N_{events}");
        
        MultTOF_Cut1->SetLineColor(6);
        MultTOF_Cut2->SetLineColor(1);
        MultTOF_Cut3->SetLineColor(5);
        MultTOF_Cut4->SetLineColor(7);
        MultTOF_Cut5->SetLineColor(8);
        MultTOF_Cut6->SetLineColor(9);
        MultTOF_Cut7->SetLineColor(46);
        MultTOF_Cut8->SetLineColor(49);

	MultTOF_Cut1->Divide(MultTOF_Rejected);
	MultTOF_Cut2->Divide(MultTOF_Rejected);
	MultTOF_Cut3->Divide(MultTOF_Rejected);
	MultTOF_Cut4->Divide(MultTOF_Rejected);
	MultTOF_Cut5->Divide(MultTOF_Rejected);
	MultTOF_Cut6->Divide(MultTOF_Rejected);
	MultTOF_Cut7->Divide(MultTOF_Rejected);
	MultTOF_Cut8->Divide(MultTOF_Rejected);

        MultTOF_Cut1->Draw();
        MultTOF_Cut2->Draw("same");
        MultTOF_Cut3->Draw("same");
        MultTOF_Cut4->Draw("same");
        MultTOF_Cut5->Draw("same");
        MultTOF_Cut6->Draw("same");
        MultTOF_Cut7->Draw("same");
        MultTOF_Cut8->Draw("same");

        TLegend *leg03 = new TLegend(0.2, 0.15, 0.6, 0.4);
        leg03->SetFillColor(0);
        leg03->SetBorderSize(0);
        leg03->SetTextSize(0.03);
        leg03->SetTextFont(42);
        
        sprintf(tr, "%s", name4);
        leg03->AddEntry(MultTOF_Cut1, tr, "l");
        sprintf(tr, "%s", name5);
        leg03->AddEntry(MultTOF_Cut2, tr, "l");
        sprintf(tr, "%s", name6);
        leg03->AddEntry(MultTOF_Cut3, tr, "l");
        sprintf(tr, "%s", name7);
        leg03->AddEntry(MultTOF_Cut4, tr, "l");
        sprintf(tr, "%s", name8);
        leg03->AddEntry(MultTOF_Cut5, tr, "l");
        sprintf(tr, "%s", name9);
        leg03->AddEntry(MultTOF_Cut6, tr, "l");
        sprintf(tr, "%s", name10);
        leg03->AddEntry(MultTOF_Cut7, tr, "l");
        sprintf(tr, "%s", name11);
        leg03->AddEntry(MultTOF_Cut8, tr, "l");

        leg03->Draw();
	c03->Print("./pics/TofHits_DiffCutsAtt.png");
        c03->SaveAs("./pics/TofHits_DiffCutsAtt.C","RECREATE");


TCanvas *c04 = new TCanvas("c04");
        c04->cd();
        gPad-> SetLogy();
        hTracks_Cut1->GetXaxis()->SetTitle("MDC tracks");
        hTracks_Cut1->GetYaxis()->SetTitle("N_{events}");

        hTracks_Cut1->SetLineColor(6);
        hTracks_Cut2->SetLineColor(1);
        hTracks_Cut3->SetLineColor(5);
        hTracks_Cut4->SetLineColor(7);
        hTracks_Cut5->SetLineColor(8);
        hTracks_Cut6->SetLineColor(9);
        hTracks_Cut7->SetLineColor(46);
        hTracks_Cut8->SetLineColor(49);

        hTracks_Cut1->Divide(hTracks_Rejected);
        hTracks_Cut2->Divide(hTracks_Rejected);
        hTracks_Cut3->Divide(hTracks_Rejected);
        hTracks_Cut4->Divide(hTracks_Rejected);
        hTracks_Cut5->Divide(hTracks_Rejected);
        hTracks_Cut6->Divide(hTracks_Rejected);
        hTracks_Cut7->Divide(hTracks_Rejected);
        hTracks_Cut8->Divide(hTracks_Rejected);

        hTracks_Cut1->Draw();
        hTracks_Cut2->Draw("same");
        hTracks_Cut3->Draw("same");
        hTracks_Cut4->Draw("same");
        hTracks_Cut5->Draw("same");
        hTracks_Cut6->Draw("same");
        hTracks_Cut7->Draw("same");
        hTracks_Cut8->Draw("same");

        TLegend *leg04 = new TLegend(0.2, 0.15, 0.6, 0.4);
        leg04->SetFillColor(0);
        leg04->SetBorderSize(0);
        leg04->SetTextSize(0.03);
        leg04->SetTextFont(42);

	sprintf(tr, "%s", name4);
        leg04->AddEntry(hTracks_Cut1, tr, "l");
        sprintf(tr, "%s", name5);
        leg04->AddEntry(hTracks_Cut2, tr, "l");
        sprintf(tr, "%s", name6);
        leg04->AddEntry(hTracks_Cut3, tr, "l");
        sprintf(tr, "%s", name7);
        leg04->AddEntry(hTracks_Cut4, tr, "l");
        sprintf(tr, "%s", name8);
        leg04->AddEntry(hTracks_Cut5, tr, "l");
        sprintf(tr, "%s", name9);
        leg04->AddEntry(hTracks_Cut6, tr, "l");
        sprintf(tr, "%s", name10);
        leg04->AddEntry(hTracks_Cut7, tr, "l");
        sprintf(tr, "%s", name11);
        leg04->AddEntry(hTracks_Cut8, tr, "l");

        leg04->Draw();
        c04->Print("./pics/MDCtrk_DiffCutsAtt.png");
        c04->SaveAs("./pics/MDCtrk_DiffCutsAtt.C","RECREATE");

TCanvas *c05 = new TCanvas("c05");
        c05->cd();
        gPad-> SetLogy();
        hTracks_Rejected->GetXaxis()->SetTitle("MDC tracks");
        hTracks_Rejected->GetYaxis()->SetTitle("N_{events}");

        hTracks_Selected->SetLineColor(2);
        hTracks_Rejected->SetLineColor(4);

	hTracks_Rejected->Divide(hTracks_All);
        hTracks_Selected->Divide(hTracks_All);

	 hTracks_Rejected->Draw();
        hTracks_Selected->Draw("same");

	TLegend *leg05 = new TLegend(0.2, 0.15, 0.6, 0.4);
        leg05->SetFillColor(0);
        leg05->SetBorderSize(0);
        leg05->SetTextSize(0.03);
        leg05->SetTextFont(42);

        sprintf(tr, "%s", name01);
        leg05->AddEntry(hTracks_Selected, tr, "l");
        sprintf(tr, "%s", name02);
        leg05->AddEntry(hTracks_Rejected, tr, "l");


	leg05->Draw();
        c05->Print("./pics/MDCtrk_SelRejDivideAll.png");
        c05->SaveAs("./pics/MDCtrk_SelRejDivideAll.C","RECREATE");

TCanvas *c06 = new TCanvas("c06");
        c06->cd();
        gPad-> SetLogy();
        MultTOF_Rejected->GetXaxis()->SetTitle("TOF hits");
        MultTOF_Rejected->GetYaxis()->SetTitle("N_{events}");

        MultTOF_Selected->SetLineColor(2);
        MultTOF_Rejected->SetLineColor(4);

        MultTOF_Rejected->Divide(MultTOF_All);
        MultTOF_Selected->Divide(MultTOF_All);

        MultTOF_Rejected->Draw();
        MultTOF_Selected->Draw("same");

        TLegend *leg06 = new TLegend(0.2, 0.15, 0.6, 0.4);
        leg06->SetFillColor(0);
        leg06->SetBorderSize(0);
        leg06->SetTextSize(0.03);
        leg06->SetTextFont(42);

        sprintf(tr, "%s", name01);
        leg06->AddEntry(MultTOF_Selected, tr, "l");
        sprintf(tr, "%s", name02);
        leg06->AddEntry(MultTOF_Rejected, tr, "l");


        leg06->Draw();
        c06->Print("./pics/MultTOF_SelRejDivideAll.png");
        c06->SaveAs("./pics/MultTOF_SelRejDivideAll.C","RECREATE");


TCanvas *c1 = new TCanvas("c1");
        c1->cd();
        gPad-> SetLogy();
     //   hTracks_Selected->SetLineColor(2);
        hTracks_Rejected->SetLineColor(4);
        hTracks_Rejected->GetXaxis()->SetTitle("MDC tracks");
        hTracks_Rejected->GetYaxis()->SetTitle("N_{events}");
       // hTracks_All->SetLineColor(3);
	hTracks_Cut1->SetLineColor(6);
	hTracks_Cut2->SetLineColor(1);
	hTracks_Cut3->SetLineColor(5);
	hTracks_Cut4->SetLineColor(7);
	hTracks_Cut5->SetLineColor(8);
	hTracks_Cut6->SetLineColor(9);
	hTracks_Cut7->SetLineColor(46);
	hTracks_Cut8->SetLineColor(49);

	hTracks_Rejected->Draw();
//        hTracks_Selected->Draw("same");
	//hPrimaryTracks_All->SetLineColor(3);
//	hTracks_All->Draw("same");
	hTracks_Cut1->Draw("same");
	hTracks_Cut2->Draw("same");
	hTracks_Cut3->Draw("same");
	hTracks_Cut4->Draw("same");
	hTracks_Cut5->Draw("same");
	hTracks_Cut6->Draw("same");
	hTracks_Cut7->Draw("same");
	hTracks_Cut8->Draw("same");

        TLegend *leg2 = new TLegend(0.2, 0.15, 0.6, 0.4);
        leg2->SetFillColor(0);
        leg2->SetBorderSize(0);
        leg2->SetTextSize(0.03);
        leg2->SetTextFont(42);
  //      sprintf(tr, "%s", name1);
    //    leg2->AddEntry(hTracks_Selected, tr, "l");
        sprintf(tr, "%s", name2);
        leg2->AddEntry(hTracks_Rejected, tr, "l");
//	sprintf(tr, "%s", name3);
  //      leg2->AddEntry(hTracks_All, tr, "l");
	sprintf(tr, "%s", name4);
        leg2->AddEntry(hTracks_Cut1, tr, "l");
	sprintf(tr, "%s", name5);
        leg2->AddEntry(hTracks_Cut2, tr, "l");
	sprintf(tr, "%s", name6);
        leg2->AddEntry(hTracks_Cut3, tr, "l");
	sprintf(tr, "%s", name7);
        leg2->AddEntry(hTracks_Cut4, tr, "l");
	sprintf(tr, "%s", name8);
        leg2->AddEntry(hTracks_Cut5, tr, "l");
	sprintf(tr, "%s", name9);
        leg2->AddEntry(hTracks_Cut6, tr, "l");
	sprintf(tr, "%s", name10);
        leg2->AddEntry(hTracks_Cut7, tr, "l");
	sprintf(tr, "%s", name11);
        leg2->AddEntry(hTracks_Cut8, tr, "l");        

	leg2->Draw();
        c1->Print("./pics/TracksRejectedbyDiffCut.png");
        c1->SaveAs("./pics/TracksRejectedbyDiffCut.C","RECREATE");

TCanvas *c2 = new TCanvas("c2");
        c2->cd();
        gPad-> SetLogy();
        MultTOF_Selected->SetLineColor(2);
        MultTOF_Rejected->SetLineColor(4);
//	MultTOF_All->SetLineColor(3);
        MultTOF_Rejected->GetXaxis()->SetTitle("TOF hits");
        MultTOF_Rejected->GetYaxis()->SetTitle("N_{events}");

	MultTOF_Rejected->Divide(MultTOF_All);
	MultTOF_Selected->Divide(MultTOF_All);

        MultTOF_Rejected->Draw();
        MultTOF_Selected->Draw("same");
//	MultTOF_All->Draw("same");

        TLegend *leg3 = new TLegend(0.2, 0.15, 0.6, 0.4);
        leg3->SetFillColor(0);
        leg3->SetBorderSize(0);
        leg3->SetTextSize(0.03);
        leg3->SetTextFont(42);
        sprintf(tr, "%s", name1);
        leg3->AddEntry(MultTOF_Selected, tr, "l");
        sprintf(tr, "%s", name2);
        leg3->AddEntry(MultTOF_Rejected, tr, "l");
//	sprintf(tr, "%s", name3);
  //      leg3->AddEntry(MultTOF_All, tr, "l");
        leg3->Draw();

        c2->Print("./pics/MultTOF_SelRejDivideAll.png");
        c2->SaveAs("./pics/MultTOF_SelRejDivideAll.C","RECREATE");


	TCanvas *c3 = new TCanvas("c3");
        c3->cd();
        gPad-> SetLogy();
        MultRPC_Selected->SetLineColor(2);
        MultRPC_Rejected->SetLineColor(4);
        MultRPC_Rejected->GetXaxis()->SetTitle("TOF hits");
 //	MultRPC_All->SetLineColor(3);
  
	MultRPC_Rejected->Divide(MultRPC_All);
	MultRPC_Selected->Divide(MultRPC_All);

        MultRPC_Rejected->GetYaxis()->SetTitle("N_{events}");
        MultRPC_Rejected->Draw();
        MultRPC_Selected->Draw("same");
//	MultRPC_All->Draw("same");

        TLegend *leg4 = new TLegend(0.2, 0.15, 0.6, 0.4);
        leg4->SetFillColor(0);
        leg4->SetBorderSize(0);
        leg4->SetTextSize(0.03);
        leg4->SetTextFont(42);
        sprintf(tr, "%s", name1);
        leg4->AddEntry(MultRPC_Selected, tr, "l");
        sprintf(tr, "%s", name2);
        leg4->AddEntry(MultRPC_Rejected, tr, "l");
//	sprintf(tr, "%s", name3);
   //     leg4->AddEntry(MultRPC_All, tr, "l");
        leg4->Draw();

        c3->Print("./pics/MultRPC_SelRejDivideAll.png");
        c3->SaveAs("./pics/MultRPC_SelRejDivideAll.C","RECREATE");

	TCanvas *c4 = new TCanvas("c1");
        c4->cd();
        gPad-> SetLogy();
        hPrimaryTracks_Selected->SetLineColor(2);
        hPrimaryTracks_Rejected->SetLineColor(4);
        hPrimaryTracks_Rejected->GetXaxis()->SetTitle("MDC tracks");
        hPrimaryTracks_Rejected->GetYaxis()->SetTitle("N_{events}");

	hPrimaryTracks_Rejected->Divide(hPrimaryTracks_All);
	hPrimaryTracks_Selected->Divide(hPrimaryTracks_All);

        hPrimaryTracks_Rejected->Draw();
        hPrimaryTracks_Selected->Draw("same");

        TLegend *leg5 = new TLegend(0.2, 0.15, 0.6, 0.4);
        leg5->SetFillColor(0);
        leg5->SetBorderSize(0);
        leg5->SetTextSize(0.03);
        leg5->SetTextFont(42);
        sprintf(tr, "%s", name1);
        leg5->AddEntry(hPrimaryTracks_Selected, tr, "l");
        sprintf(tr, "%s", name2);
        leg5->AddEntry(hPrimaryTracks_Rejected, tr, "l");
        leg5->Draw();

        c4->Print("./pics/PrimaryTracks_SelRejDivideAll.png");
        c4->SaveAs("./pics/PrimaryTracks_SelRejDivideAll.C","RECREATE");

	TCanvas *fhMDCtrk_PrimTrk = new TCanvas("fhMDCtrk_PrimTrk");
        fhMDCtrk_PrimTrk ->cd();
        gPad-> SetLogz();
        hMDCtrk_PrimTrk->GetXaxis()->SetTitle("MDC tracks");
        hMDCtrk_PrimTrk->GetYaxis()->SetTitle("Primary Tracks");
        hMDCtrk_PrimTrk->Draw("COLZ");

        fhMDCtrk_PrimTrk->Print("hMDCtrk_PrimTrk.png");
        fhMDCtrk_PrimTrk->SaveAs("hMDCtrk_PrimTrk_.C","RECREATE");

TCanvas *fhTOFhit_PrimTrk = new TCanvas("fhTOFhit_PrimTrk");
        fhTOFhit_PrimTrk->cd();
        gPad-> SetLogz();
        hTOFhit_PrimTrk->GetXaxis()->SetTitle("TOF hits");
        hTOFhit_PrimTrk->GetYaxis()->SetTitle("Primary Tracks");
        hTOFhit_PrimTrk->Draw("COLZ");

        fhTOFhit_PrimTrk->Print("hTOFhit_PrimTrk.png");
        fhTOFhit_PrimTrk->SaveAs("hTOFhit_PrimTrk_.C","RECREATE");

TCanvas *fhRPChit_PrimTrk = new TCanvas("fhRPChit_PrimTrk");
        fhRPChit_PrimTrk->cd();
        gPad-> SetLogz();
        hRPChit_PrimTrk->GetXaxis()->SetTitle("RPC hits");
        hRPChit_PrimTrk->GetYaxis()->SetTitle("Primary Tracks");
        hRPChit_PrimTrk->Draw("COLZ");

        fhRPChit_PrimTrk->Print("hRPChit_PrimTrk.png");
        fhRPChit_PrimTrk->SaveAs("hRPChit_PrimTrk_.C","RECREATE");

*/	
}
