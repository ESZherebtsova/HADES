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
#include "TStyle.h"
#include "TLatex.h"

void drawFWdistrToFit () {

	TChain *tree1=new TChain("tree");
	tree1->Add("/lustre/nyx/hades/user/ezherebt/treeMaker/output/Nov_27_12_48/tree_12108160806.root");

	TH1F *hFWhit=new TH1F ("hFWhit","",60,0,60);
	TH1F *hFWhit2=new TH1F ("hFWhit2","",60,0,60);	
	TH1F *hTOFhit=new TH1F("hTOFhit","",120,0,120);
	TH1F *hTOFhit2=new TH1F("hTOFhit2","",120,0,120);
	TH1F *hRPChit=new TH1F("hRPChit","",200,0,200);
	TH1F *hRPChit2=new TH1F("hRPChit2","",200,0,200);
	TH1F *hMDCtrk=new TH1F("hMDCtrk","",120,0,120);
	TH1F *hMDCtrk2=new TH1F("hMDCtrk2","",120,0,120);
	TH1F *hFWcharge=new TH1F("hFWcharge","",170,0,17000);
	TH1F *hFWcharge2=new TH1F("hFWcharge2","",170,0,17000);
	TH1F *MultTOF_All=new TH1F("MultTOF_All", "", 100,0,100);
	TH1F *MultTOF_All2=new TH1F("MultTOF_All2", "", 100,0,100);
	TH2F *hRPChit_FWhit=new TH2F("hRPChit_FWhit","",60,0,60,200,0,200);
	TH2F *hRPChit_FWhit2=new TH2F("hRPChit_FWhit2","",60,0,60,200,0,200);
	TH2F *hMDCtrk_FWhit=new TH2F("hMDCtrk_FWhit","",60,0,60,120,0,120);
	TH2F *hMDCtrk_FWhit2=new TH2F("hMDCtrk_FWhit2","",60,0,60,120,0,120);
	TH2F *hTOFhit_FWhit=new TH2F("hTOFhit_FWhit","",60,0,60,100,0,100);
	TH2F *hTOFhit_FWhit2=new TH2F("hTOFhit_FWhit2","",60,0,60,100,0,100);
	TH2F *hRPChit_FWcharge=new TH2F("hRPChit_FWcharge","",170,0,17000,200,0,200);
	TH2F *hRPChit_FWcharge2=new TH2F("hRPChit_FWcharge2","",170,0,17000,200,0,200);
	TH2F *hMDCtrk_FWcharge=new TH2F("hMDCtrk_FWcharge","",170,0,17000,120,0,120);
	TH2F *hMDCtrk_FWcharge2=new TH2F("hMDCtrk_FWcharge2","",170,0,17000,120,0,120);
	TH2F *hTOFhit_FWcharge=new TH2F("hTOFhit_FWcharge","",170,0,17000,100,0,100);
	TH2F *hTOFhit_FWcharge2=new TH2F("hTOFhit_FWcharge2","",170,0,17000,100,0,100);


	TH1F *hFWhit_Cut=new TH1F ("hFWhit_Cut","",60,0,60);
        TH1F *hFWhit2_Cut=new TH1F ("hFWhit2_Cut","",60,0,60);
        TH1F *hTOFhit_Cut=new TH1F("hTOFhit_Cut","",120,0,120);
        TH1F *hTOFhit2_Cut=new TH1F("hTOFhit2_Cut","",120,0,120);
        TH1F *hRPChit_Cut=new TH1F("hRPChit_Cut","",200,0,200);
        TH1F *hRPChit2_Cut=new TH1F("hRPChit2_Cut","",200,0,200);
        TH1F *hMDCtrk_Cut=new TH1F("hMDCtrk_Cut","",120,0,120);
        TH1F *hMDCtrk2_Cut=new TH1F("hMDCtrk2_Cut","",120,0,120);
        TH1F *hFWcharge_Cut=new TH1F("hFWcharge_Cut","",170,0,17000);
        TH1F *hFWcharge2_Cut=new TH1F("hFWcharge2_Cut","",170,0,17000);
        TH1F *MultTOF_All_Cut=new TH1F("MultTOF_All_Cut", "", 100,0,100);
        TH1F *MultTOF_All2_Cut=new TH1F("MultTOF_All2_Cut", "", 100,0,100);
        TH2F *hRPChit_FWhit_Cut=new TH2F("hRPChit_FWhit_Cut","",60,0,60,200,0,200);
        TH2F *hRPChit_FWhit2_Cut=new TH2F("hRPChit_FWhit2_Cut","",60,0,60,200,0,200);
        TH2F *hMDCtrk_FWhit_Cut=new TH2F("hMDCtrk_FWhit_Cut","",60,0,60,120,0,120);
        TH2F *hMDCtrk_FWhit2_Cut=new TH2F("hMDCtrk_FWhit2_Cut","",60,0,60,120,0,120);
        TH2F *hTOFhit_FWhit_Cut=new TH2F("hTOFhit_FWhit_Cut","",60,0,60,100,0,100);
        TH2F *hTOFhit_FWhit2_Cut=new TH2F("hTOFhit_FWhit2_Cut","",60,0,60,100,0,100);
	TH2F *hRPChit_FWcharge_Cut=new TH2F("hRPChit_FWcharge_Cut","",170,0,17000,200,0,200);
        TH2F *hRPChit_FWcharge2_Cut=new TH2F("hRPChit_FWcharge2_Cut","",170,0,17000,200,0,200);
        TH2F *hMDCtrk_FWcharge_Cut=new TH2F("hMDCtrk_FWcharge_Cut","",170,0,17000,120,0,120);
        TH2F *hMDCtrk_FWcharge2_Cut=new TH2F("hMDCtrk_FWcharge2_Cut","",170,0,17000,120,0,120);
        TH2F *hTOFhit_FWcharge_Cut=new TH2F("hTOFhit_FWcharge_Cut","",170,0,17000,100,0,100);
        TH2F *hTOFhit_FWcharge2_Cut=new TH2F("hTOFhit_FWcharge2_Cut","",170,0,17000,100,0,100);


	TH1F *hFWhit_ring1=new TH1F ("hFWhit_ring1","FW hits ring 1",45,0,45);
	TH1F *hFWhit_ring12=new TH1F ("hFWhit_ring12","FW hits ring 1-2",45,0,45);
	TH1F *hFWhit_ring13=new TH1F ("hFWhit_ring13","FW hits ring 1-3",45,0,45);
	TH1F *hFWhit_ring14=new TH1F ("hFWhit_ring14","FW hits ring 1-4",45,0,45);
	TH1F *hFWhit_ring56=new TH1F ("hFWhit_ring56", "FW hits ring 5-6",45,0,45);
	TH1F *hFWhit_ring57=new TH1F ("hFWhit_ring57", "FW hits ring 5-7",45,0,45);
	TH1F *hFWhit_ring58=new TH1F ("hFWhit_ring58", "FW hits ring 5-8",45,0,45);
	TH1F *hFWhit_ring59=new TH1F ("hFWhit_ring59", "FW hits ring 5-9",45,0,45);

	TH2F *hTofHits_FWhits_ring1=new TH2F ("hTofHits_FWhits_ring1", "TOF hits vs FW hits ring 1",45,0,45,120,0,120);
	TH2F *hTofHits_FWhits_ring12=new TH2F ("hTofHits_FWhits_ring12", "TOF hits vs FW hits ring 1-2",45,0,45,120,0,120);
	TH2F *hTofHits_FWhits_ring13=new TH2F ("hTofHits_FWhits_ring13", "TOF hits vs FW hits ring 1-3",45,0,45,120,0,120);
	TH2F *hTofHits_FWhits_ring14=new TH2F ("hTofHits_FWhits_ring14", "TOF hits vs FW hits ring 1-4",45,0,45,120,0,120);
	TH2F *hTofHits_FWhits_ring56=new TH2F ("hTofHits_FWhits_ring56", "TOF hits vs FW hits ring 5-6",45,0,45,120,0,120);
	TH2F *hTofHits_FWhits_ring57=new TH2F ("hTofHits_FWhits_ring57", "TOF hits vs FW hits ring 5-7",45,0,45,120,0,120);
	TH2F *hTofHits_FWhits_ring58=new TH2F ("hTofHits_FWhits_ring58", "TOF hits vs FW hits ring 5-8",45,0,45,120,0,120);
	TH2F *hTofHits_FWhits_ring59=new TH2F ("hTofHits_FWhits_ring59", "TOF hits vs FW hits ring 5-9",45,0,45,120,0,120);

	TF1 *tf1=new TF1("tf2","-25*x+100",0,4);
	TF1 *tf2=new TF1("tf2","-10*x+100",0,10);
	TF1 *tf3=new TF1("tf2","-30*x+60",0,2);
	TF1 *tf4=new TF1("tf2","-5*x+40",0,8);
	TF1 *tf5=new TF1("tf2","-20*x+40",0,2);
	TF1 *tf6=new TF1("tf2","-5*x+40",0,8);
	TF1 *tf7=new TF1("tf2","-12./225.*x+120",0,2250);
	TF1 *tf8=new TF1("tf2","-12./225.*x+50",0,2250);
	TF1 *tf9=new TF1("tf2","-12./225.*x+60",0,2250);


	 TFile* TreeFile = new TFile("./RootTrees/AllDistToFit.root","RECREATE");

	Float_t k1;
	Float_t b1;
	Float_t  Xcoor;
	Int_t nTofHitsCut;
        Int_t nRpcClustCut;
        Bool_t trigInd[4];
        Bool_t cuts[8];
        Float_t vZ,vX,vY,vChi2;
        Float_t wallChargeTot_mod[305];
        Short_t nWallHitsTot;
        Float_t wallChargeTot;
        Float_t wallHitTime[200];
        Float_t wallHitDistance[200];
        Float_t wallHitPhi[200];
        Float_t FWphi,FWtime,FWdist;
        Short_t  ModInd;
        Short_t wallModuleIndex[200];
        Float_t hit_beta;
        Short_t wallHitRing[200];
        Short_t ring;
        Float_t wallHitCharge[200];
        Float_t hitCharge;
        Float_t ChargeTot;
        Short_t FWhits, count1;
	Short_t count12, count13, count14, count;
	Short_t count56, count57, count58, count59;
	Short_t numbertrk, nTracks;
	Float_t DCAxy[200], DCAz[200];
	Float_t zToBeam, rToBeam;

	tree1->SetBranchAddress("trigInd", &trigInd);
        tree1->SetBranchAddress("wallHitCharge", &wallHitCharge);
        tree1->SetBranchAddress("wallHitTime", &wallHitTime);
        tree1->SetBranchAddress("wallHitDistance", &wallHitDistance);
        tree1->SetBranchAddress("wallHitPhi",&wallHitPhi);
        tree1->SetBranchAddress("wallChargeTot", &wallChargeTot);
        tree1->SetBranchAddress("nWallHitsTot", &nWallHitsTot);
        tree1->SetBranchAddress("vZ", &vZ);
        tree1->SetBranchAddress("vX", &vX);
        tree1->SetBranchAddress("vY", &vY);
        tree1->SetBranchAddress("vChi2", &vChi2);
        tree1->SetBranchAddress("cuts", &cuts);
        tree1->SetBranchAddress("wallChargeTot_mod", &wallChargeTot_mod);
        tree1->SetBranchAddress("wallModuleIndex", &wallModuleIndex);
        tree1->SetBranchAddress("wallHitRing", &wallHitRing);
        tree1->SetBranchAddress("nTofHitsCut", &nTofHitsCut);
        tree1->SetBranchAddress("nRpcClustCut", &nRpcClustCut);
	tree1->SetBranchAddress("nTracks", &nTracks);
	tree1->SetBranchAddress("DCAxy", &DCAxy);
	tree1->SetBranchAddress("DCAz", &DCAz);


	int entry=0;
        while(entry < tree1->GetEntries()) {
                tree1->GetEntry(entry);

                if (cuts[1] && cuts[2] && cuts[3] && cuts[4] && cuts[5] && cuts[6] && cuts[7] &&
		     vZ>=-60 && vZ<=0 && (pow(vX*vX+vY*vY,0.5)<3) && vChi2>0.5 && vChi2<22) {

			hitCharge=0;
                       	ChargeTot=0;
               		count1=0;
			count12=0;
			count13=0;
			count14=0;
			count56=0;
			count57=0;
			count58=0;
			count59=0;
			count=0;

          		for (short j=0;j<nWallHitsTot;j++) {

          	                 FWphi=wallHitPhi[j];
                	         FWdist=wallHitDistance[j];
                       		 FWtime=wallHitTime[j];
                       		 ModInd=wallModuleIndex[j];
                       		 ring=wallHitRing[j];
                       		 hit_beta = wallHitDistance[j]/wallHitTime[j]/299.792458;
                       		 hitCharge+=wallHitCharge[j];

				if      (FWtime>10 && FWtime<120 && FWdist>6800 &&  wallHitCharge[j]<600 &&  
					((ring<=4 && wallHitCharge[j]>80 && hit_beta>0.84 && hit_beta<1.) ||
                                        ((ring==5||ring==6) && wallHitCharge[j]>85 && hit_beta>0.85 && hit_beta<1.) ||
                                        (ring>6            && wallHitCharge[j]>86 && hit_beta>0.80 && hit_beta<1.) ) ) {

                    		        ChargeTot+=wallHitCharge[j];
        		               
				count++;
				if (ring==1) count1++;
				if (ring>0 && ring<3)  count12++;
				if (ring>0 && ring<4) count13++;
				if (ring>0 && ring<5) count14++;
				if (ring>4 && ring<7) count56++;
				if (ring>4 && ring<8) count57++;
				if (ring>4 && ring<9) count58++;
				if (ring>4 && ring<10) count59++;

				} //end  FW cuts
			} //end wall hits loop


			numbertrk=0;
			for (short i=0;i<nTracks;i++) {

				rToBeam=DCAxy[i];
				zToBeam=DCAz[i];

				if (rToBeam<10 && zToBeam<10) numbertrk++;

				}

				Xcoor=(nTofHitsCut-b1)/k1; 

			 if (trigInd[1]) {
					hFWhit->Fill(count);
					hTOFhit->Fill(nTofHitsCut);
					hRPChit->Fill(nRpcClustCut);
					hMDCtrk->Fill(numbertrk);
					hFWcharge->Fill(wallChargeTot);
					hRPChit_FWhit->Fill(count,nRpcClustCut);
					hTOFhit_FWhit->Fill(count,nTofHitsCut);
					hMDCtrk_FWhit->Fill(count,numbertrk);
					hRPChit_FWcharge->Fill(wallChargeTot,nRpcClustCut);
					hTOFhit_FWcharge->Fill(wallChargeTot,nTofHitsCut);
					hMDCtrk_FWcharge->Fill(wallChargeTot,numbertrk);
					}

			if (trigInd[2]) {

					hFWhit2->Fill(count);
                                        hTOFhit2->Fill(nTofHitsCut);
                                        hRPChit2->Fill(nRpcClustCut);
                                        hMDCtrk2->Fill(numbertrk);
                                        hFWcharge2->Fill(wallChargeTot);
                                        hRPChit_FWhit2->Fill(count,nRpcClustCut);
                                        hTOFhit_FWhit2->Fill(count,nTofHitsCut);
                                        hMDCtrk_FWhit2->Fill(count,numbertrk);
					hRPChit_FWcharge2->Fill(wallChargeTot,nRpcClustCut);
                                        hTOFhit_FWcharge2->Fill(wallChargeTot,nTofHitsCut);
                                        hMDCtrk_FWcharge2->Fill(wallChargeTot,numbertrk);

					}

			hFWhit_ring1->Fill(count1);
			hFWhit_ring12->Fill(count12);
			hFWhit_ring13->Fill(count13);
			hFWhit_ring14->Fill(count14);
			hFWhit_ring56->Fill(count56);

			if ((nTofHitsCut>-4.5*count59+45) || (count59>(nTofHitsCut-45)/4.5)) {
			
			hFWhit_ring57->Fill(count57);
			hFWhit_ring58->Fill(count58);
			hFWhit_ring59->Fill(count59);	
					}

			hTofHits_FWhits_ring1->Fill(count1,nTofHitsCut);
			hTofHits_FWhits_ring12->Fill(count12,nTofHitsCut);
			hTofHits_FWhits_ring13->Fill(count13,nTofHitsCut);
			hTofHits_FWhits_ring14->Fill(count14,nTofHitsCut);
			hTofHits_FWhits_ring56->Fill(count56,nTofHitsCut);
			hTofHits_FWhits_ring57->Fill(count57,nTofHitsCut);
			hTofHits_FWhits_ring58->Fill(count58,nTofHitsCut);
			hTofHits_FWhits_ring59->Fill(count59,nTofHitsCut);
		}
		entry++;
	} //end event loop


/*	TCanvas *c131=new TCanvas("c131","",800,600);
        c131->cd();
        gPad->SetLogz();
        gStyle->SetOptStat(0);
        hRPChit_FWhit_Cut->GetYaxis()->SetTitle("RPC hits");
        hRPChit_FWhit_Cut->GetXaxis()->SetTitle("FW hits");
        hRPChit_FWhit_Cut->GetXaxis()->SetTitleSize(0.06);
        hRPChit_FWhit_Cut->GetYaxis()->SetTitleSize(0.06);
        hRPChit_FWhit_Cut->GetXaxis()->SetLabelSize(0.04);
        hRPChit_FWhit_Cut->GetYaxis()->SetLabelSize(0.04);
        hRPChit_FWhit_Cut->Draw("colz");

        TLatex *l131=new TLatex(20,206,"PT2 trigger");
        l131->Draw();

        TLatex *l131_=new TLatex(30,180,"Au-Au, 1.23A GeV");
        l131_->Draw();

        c131->SaveAs("./picsFWtoFit/hRPChit_FWhit_PT2_Cut.C");
        c131->Print("./picsFWtoFit/hRPChit_FWhit_PT2_Cut.png");

        TCanvas *c141=new TCanvas("c141","",800,600);
        c141->cd();
        gPad->SetLogz();
        gStyle->SetOptStat(0);
        hRPChit_FWhit2_Cut->GetYaxis()->SetTitle("RPC hits");
        hRPChit_FWhit2_Cut->GetXaxis()->SetTitle("FW hits");
        hRPChit_FWhit2_Cut->GetXaxis()->SetTitleSize(0.06);
        hRPChit_FWhit2_Cut->GetYaxis()->SetTitleSize(0.06);
        hRPChit_FWhit2_Cut->GetXaxis()->SetLabelSize(0.04);
        hRPChit_FWhit2_Cut->GetYaxis()->SetLabelSize(0.04);
        hRPChit_FWhit2_Cut->Draw("colz");

        TLatex *l141=new TLatex(20,206,"PT3 trigger");
        l141->Draw();
        TLatex *l141_=new TLatex(30,180,"Au-Au, 1.23A GeV");
        l141_->Draw();

        c141->SaveAs("./picsFWtoFit/hRPChit_FWhit_PT3_Cut.C");
        c141->Print("./picsFWtoFit/hRPChit_FWhit_PT3_Cut.png");

        TCanvas *c151=new TCanvas("c151","",800,600);
        c151->cd();
        gPad->SetLogz();
        gStyle->SetOptStat(0);
        hTOFhit_FWhit_Cut->GetYaxis()->SetTitle("TOF hits");
        hTOFhit_FWhit_Cut->GetXaxis()->SetTitle("FW hits");
        hTOFhit_FWhit_Cut->GetXaxis()->SetTitleSize(0.06);
        hTOFhit_FWhit_Cut->GetYaxis()->SetTitleSize(0.06);
        hTOFhit_FWhit_Cut->GetXaxis()->SetLabelSize(0.04);
        hTOFhit_FWhit_Cut->GetYaxis()->SetLabelSize(0.04);
        hTOFhit_FWhit_Cut->Draw("colz");

	TLatex *l151=new TLatex(20,106,"PT2 trigger");
        l151->Draw();
        TLatex *l151_=new TLatex(30,90,"Au-Au, 1.23A GeV");
        l151_->Draw();

        c151->SaveAs("./picsFWtoFit/hTOFhit_FWhit_PT2_Cut.C");
        c151->Print("./picsFWtoFit/hTOFhit_FWhit_PT2_Cut.png");


        TCanvas *c161=new TCanvas("c161","",800,600);
        c161->cd();
        gPad->SetLogz();
        gStyle->SetOptStat(0);
        hTOFhit_FWhit2_Cut->GetYaxis()->SetTitle("TOF hits");
        hTOFhit_FWhit2_Cut->GetXaxis()->SetTitle("FW hits");
        hTOFhit_FWhit2_Cut->GetXaxis()->SetTitleSize(0.06);
        hTOFhit_FWhit2_Cut->GetYaxis()->SetTitleSize(0.06);
        hTOFhit_FWhit2_Cut->GetXaxis()->SetLabelSize(0.04);
        hTOFhit_FWhit2_Cut->GetYaxis()->SetLabelSize(0.04);
        hTOFhit_FWhit2_Cut->Draw("colz");

        TLatex *l161=new TLatex(20,106,"PT3 trigger");
        l161->Draw();
        TLatex *l161_=new TLatex(30,90,"Au-Au, 1.23A GeV");
        l161_->Draw();

        c161->SaveAs("./picsFWtoFit/hTOFhit_FWhit_PT3_Cut.C");
        c161->Print("./picsFWtoFit/hTOFhit_FWhit_PT3_Cut.png");

	TCanvas *c171=new TCanvas("c171","",800,600);
        c171->cd();
        gPad->SetLogz();
        gStyle->SetOptStat(0);
        hMDCtrk_FWhit_Cut->GetYaxis()->SetTitle("MDC tracks");
        hMDCtrk_FWhit_Cut->GetXaxis()->SetTitle("FW hits");
        hMDCtrk_FWhit_Cut->GetXaxis()->SetTitleSize(0.06);
        hMDCtrk_FWhit_Cut->GetYaxis()->SetTitleSize(0.06);
        hMDCtrk_FWhit_Cut->GetXaxis()->SetLabelSize(0.04);
        hMDCtrk_FWhit_Cut->GetYaxis()->SetLabelSize(0.04);
        hMDCtrk_FWhit_Cut->Draw("colz");

        TLatex *l171=new TLatex(20,126,"PT2 trigger");
        l171->Draw();
        TLatex *l171_=new TLatex(30,100,"Au-Au, 1.23A GeV");
        l171_->Draw();

        c171->SaveAs("./picsFWtoFit/hMDCtrk_FWhit_PT2_Cut.C");
        c171->Print("./picsFWtoFit/hMDCtrk_FWhit_PT2_Cut.png");

        TCanvas *c181=new TCanvas("c181","",800,600);
        c181->cd();
        gPad->SetLogz();
        gStyle->SetOptStat(0);
        hMDCtrk_FWhit2_Cut->GetYaxis()->SetTitle("MDC tracks");
        hMDCtrk_FWhit2_Cut->GetXaxis()->SetTitle("FW hits");
        hMDCtrk_FWhit2_Cut->GetXaxis()->SetTitleSize(0.06);
        hMDCtrk_FWhit2_Cut->GetYaxis()->SetTitleSize(0.06);
        hMDCtrk_FWhit2_Cut->GetXaxis()->SetLabelSize(0.04);
        hMDCtrk_FWhit2_Cut->GetYaxis()->SetLabelSize(0.04);
        hMDCtrk_FWhit2_Cut->Draw("colz");

        TLatex *l181=new TLatex(20,126,"PT3 trigger");
        l181->Draw();
        TLatex *l181_=new TLatex(30,100,"Au-Au, 1.23A GeV");
        l181_->Draw();

        c181->SaveAs("./picsFWtoFit/hMDCtrk_FWhit_PT3_Cut.C");
        c181->Print("./picsFWtoFit/hMDCtrk_FWhit_PT3_Cut.png");


        TCanvas *c191=new TCanvas("c191","",800,600);
        c191->cd();
        gPad->SetLogz();
        gStyle->SetOptStat(0);
        hRPChit_FWcharge_Cut->GetYaxis()->SetTitle("RPC hits");
        hRPChit_FWcharge_Cut->GetXaxis()->SetTitle("FW charge, [GeV]");
        hRPChit_FWcharge_Cut->GetXaxis()->SetTitleSize(0.06);
        hRPChit_FWcharge_Cut->GetYaxis()->SetTitleSize(0.06);
        hRPChit_FWcharge_Cut->GetXaxis()->SetLabelSize(0.04);
        hRPChit_FWcharge_Cut->GetYaxis()->SetLabelSize(0.04);
        hRPChit_FWcharge_Cut->Draw("colz");

	TLatex *l191=new TLatex(6000,206,"PT2 trigger");
        l191->Draw();
        TLatex *l191_=new TLatex(8000,180,"Au-Au, 1.23A GeV");
        l191_->Draw();

        c191->SaveAs("./picsFWtoFit/hRPChit_FWcharge_PT2_Cut.C");
        c191->Print("./picsFWtoFit/hRPChit_FWcharge_PT2_Cut.png");

        TCanvas *c201=new TCanvas("c201","",800,600);
        c201->cd();
        gPad->SetLogz();
        gStyle->SetOptStat(0);
        hRPChit_FWcharge2_Cut->GetYaxis()->SetTitle("RPC hits");
        hRPChit_FWcharge2_Cut->GetXaxis()->SetTitle("FW charge, [GeV]");
        hRPChit_FWcharge2_Cut->GetXaxis()->SetTitleSize(0.06);
        hRPChit_FWcharge2_Cut->GetYaxis()->SetTitleSize(0.06);
        hRPChit_FWcharge2_Cut->GetXaxis()->SetLabelSize(0.04);
        hRPChit_FWcharge2_Cut->GetYaxis()->SetLabelSize(0.04);
        hRPChit_FWcharge2_Cut->Draw("colz");

        TLatex *l201=new TLatex(6000,206,"PT3 trigger");
        l201->Draw();
        TLatex *l201_=new TLatex(8000,180,"Au-Au, 1.23A GeV");
        l201_->Draw();

        c201->SaveAs("./picsFWtoFit/hRPChit_FWcharge_PT3_Cut.C");
        c201->Print("./picsFWtoFit/hRPChit_FWcharge_PT3_Cut.png");

        TCanvas *c211=new TCanvas("c211","",800,600);
        c211->cd();
        gPad->SetLogz();
        gStyle->SetOptStat(0);
        hTOFhit_FWcharge_Cut->GetYaxis()->SetTitle("TOF hits");
        hTOFhit_FWcharge_Cut->GetXaxis()->SetTitle("FW charge, [GeV]");
        hTOFhit_FWcharge_Cut->GetXaxis()->SetTitleSize(0.06);
        hTOFhit_FWcharge_Cut->GetYaxis()->SetTitleSize(0.06);
        hTOFhit_FWcharge_Cut->GetXaxis()->SetLabelSize(0.04);
        hTOFhit_FWcharge_Cut->GetYaxis()->SetLabelSize(0.04);
        hTOFhit_FWcharge_Cut->Draw("colz");

        TLatex *l211=new TLatex(6000,106,"PT2 trigger");
        l211->Draw();
        TLatex *l211_=new TLatex(8000,90,"Au-Au, 1.23A GeV");
        l211_->Draw();

        c211->SaveAs("./picsFWtoFit/hTOFhit_FWcharge_PT2_Cut.C");
        c211->Print("./picsFWtoFit/hTOFhit_FWcharge_PT2_Cut.png");

	TCanvas *c221=new TCanvas("c221","",800,600);
        c221->cd();
        gPad->SetLogz();
        gStyle->SetOptStat(0);
        hTOFhit_FWcharge2_Cut->GetYaxis()->SetTitle("TOF hits");
        hTOFhit_FWcharge2_Cut->GetXaxis()->SetTitle("FW charge, [GeV]");
        hTOFhit_FWcharge2_Cut->GetXaxis()->SetTitleSize(0.06);
        hTOFhit_FWcharge2_Cut->GetYaxis()->SetTitleSize(0.06);
        hTOFhit_FWcharge2_Cut->GetXaxis()->SetLabelSize(0.04);
        hTOFhit_FWcharge2_Cut->GetYaxis()->SetLabelSize(0.04);
        hTOFhit_FWcharge2_Cut->Draw("colz");

        TLatex *l221=new TLatex(6000,106,"PT3 trigger");
        l221->Draw();
        TLatex *l221_=new TLatex(8000,90,"Au-Au, 1.23A GeV");
        l221_->Draw();

        c221->SaveAs("./picsFWtoFit/hTOFhit_FWcharge_PT3_Cut.C");
        c221->Print("./picsFWtoFit/hTOFhit_FWcharge_PT3_Cut.png");

        TCanvas *c231=new TCanvas("c231","",800,600);
        c231->cd();
        gPad->SetLogz();
        gStyle->SetOptStat(0);
        hMDCtrk_FWcharge_Cut->GetYaxis()->SetTitle("MDC tracks");
        hMDCtrk_FWcharge_Cut->GetXaxis()->SetTitle("FW charge, [GeV]");
        hMDCtrk_FWcharge_Cut->GetXaxis()->SetTitleSize(0.06);
        hMDCtrk_FWcharge_Cut->GetYaxis()->SetTitleSize(0.06);
        hMDCtrk_FWcharge_Cut->GetXaxis()->SetLabelSize(0.04);
        hMDCtrk_FWcharge_Cut->GetYaxis()->SetLabelSize(0.04);
        hMDCtrk_FWcharge_Cut->Draw("colz");

        TLatex *l231=new TLatex(6000,126,"PT2 trigger");
        l231->Draw();
        TLatex *l231_=new TLatex(8000,100,"Au-Au, 1.23A GeV");
        l231_->Draw();

        c231->SaveAs("./picsFWtoFit/hMDCtrk_FWcharge_PT2_Cut.C");
        c231->Print("./picsFWtoFit/hMDCtrk_FWcharge_PT2_Cut.png");

        TCanvas *c241=new TCanvas("c241","",800,600);
        c241->cd();
        gPad->SetLogz();
        gStyle->SetOptStat(0);
        hMDCtrk_FWcharge2_Cut->GetYaxis()->SetTitle("MDC tracks");
        hMDCtrk_FWcharge2_Cut->GetXaxis()->SetTitle("FW charge, [GeV]");
        hMDCtrk_FWcharge2_Cut->GetXaxis()->SetTitleSize(0.06);
        hMDCtrk_FWcharge2_Cut->GetYaxis()->SetTitleSize(0.06);
        hMDCtrk_FWcharge2_Cut->GetXaxis()->SetLabelSize(0.04);
        hMDCtrk_FWcharge2_Cut->GetYaxis()->SetLabelSize(0.04);
        hMDCtrk_FWcharge2_Cut->Draw("colz");

        TLatex *l241=new TLatex(6000,126,"PT3 trigger");
        l241->Draw();
        TLatex *l241_=new TLatex(8000,100,"Au-Au, 1.23A GeV");
        l241_->Draw();

	c241->SaveAs("./picsFWtoFit/hMDCtrk_FWcharge_PT3_Cut.C");
        c241->Print("./picsFWtoFit/hMDCtrk_FWcharge_PT3_Cut.png");
*/


	TCanvas *c13=new TCanvas("c13","",800,600);
        c13->cd();
        gPad->SetLogz();
	gStyle->SetOptStat(0);
        hRPChit_FWhit->GetYaxis()->SetTitle("RPC hits");
        hRPChit_FWhit->GetXaxis()->SetTitle("FW hits");
	hRPChit_FWhit->GetXaxis()->SetTitleSize(0.06);
	hRPChit_FWhit->GetYaxis()->SetTitleSize(0.06);
	hRPChit_FWhit->GetXaxis()->SetLabelSize(0.04);
	hRPChit_FWhit->GetYaxis()->SetLabelSize(0.04);
        hRPChit_FWhit->Draw("colz");

	TLatex *l13=new TLatex(20,206,"PT2 trigger");
	l13->Draw();

	TLatex *l13_=new TLatex(30,180,"Au-Au, 1.23A GeV");
        l13_->Draw();

        c13->SaveAs("./picsFWtoFit/hRPChit_FWhit_PT2.C");
        c13->Print("./picsFWtoFit/hRPChit_FWhit_PT2.png");

	TCanvas *c14=new TCanvas("c14","",800,600);
        c14->cd();
        gPad->SetLogz();
	gStyle->SetOptStat(0);
        hRPChit_FWhit2->GetYaxis()->SetTitle("RPC hits");
        hRPChit_FWhit2->GetXaxis()->SetTitle("FW hits");
        hRPChit_FWhit2->GetXaxis()->SetTitleSize(0.06);
        hRPChit_FWhit2->GetYaxis()->SetTitleSize(0.06);
        hRPChit_FWhit2->GetXaxis()->SetLabelSize(0.04);
        hRPChit_FWhit2->GetYaxis()->SetLabelSize(0.04);
        hRPChit_FWhit2->Draw("colz");

        TLatex *l14=new TLatex(20,206,"PT3 trigger");
        l14->Draw();
	TLatex *l14_=new TLatex(30,180,"Au-Au, 1.23A GeV");
        l14_->Draw();

        c14->SaveAs("./picsFWtoFit/hRPChit_FWhit_PT3.C");
        c14->Print("./picsFWtoFit/hRPChit_FWhit_PT3.png");

	TCanvas *c15=new TCanvas("c15","",800,600);
        c15->cd();
        gPad->SetLogz();
	gStyle->SetOptStat(0);
        hTOFhit_FWhit->GetYaxis()->SetTitle("TOF hits");
        hTOFhit_FWhit->GetXaxis()->SetTitle("FW hits");
        hTOFhit_FWhit->GetXaxis()->SetTitleSize(0.06);
        hTOFhit_FWhit->GetYaxis()->SetTitleSize(0.06);
        hTOFhit_FWhit->GetXaxis()->SetLabelSize(0.04);
        hTOFhit_FWhit->GetYaxis()->SetLabelSize(0.04);
        hTOFhit_FWhit->Draw("colz");

        TLatex *l15=new TLatex(20,106,"PT2 trigger");
        l15->Draw();
	TLatex *l15_=new TLatex(30,90,"Au-Au, 1.23A GeV");
        l15_->Draw();

        c15->SaveAs("./picsFWtoFit/hTOFhit_FWhit_PT2.C");
        c15->Print("./picsFWtoFit/hTOFhit_FWhit_PT2.png");


	TCanvas *c16=new TCanvas("c16","",800,600);
        c16->cd();
        gPad->SetLogz();
	gStyle->SetOptStat(0);
        hTOFhit_FWhit2->GetYaxis()->SetTitle("TOF hits");
        hTOFhit_FWhit2->GetXaxis()->SetTitle("FW hits");
        hTOFhit_FWhit2->GetXaxis()->SetTitleSize(0.06);
        hTOFhit_FWhit2->GetYaxis()->SetTitleSize(0.06);
        hTOFhit_FWhit2->GetXaxis()->SetLabelSize(0.04);
        hTOFhit_FWhit2->GetYaxis()->SetLabelSize(0.04);
        hTOFhit_FWhit2->Draw("colz");

        TLatex *l16=new TLatex(20,106,"PT3 trigger");
        l16->Draw();
	TLatex *l16_=new TLatex(30,90,"Au-Au, 1.23A GeV");
        l16_->Draw();

        c16->SaveAs("./picsFWtoFit/hTOFhit_FWhit_PT3.C");
        c16->Print("./picsFWtoFit/hTOFhit_FWhit_PT3.png");

	 TCanvas *c17=new TCanvas("c17","",800,600);
        c17->cd();
        gPad->SetLogz();
	gStyle->SetOptStat(0);
        hMDCtrk_FWhit->GetYaxis()->SetTitle("MDC tracks");
        hMDCtrk_FWhit->GetXaxis()->SetTitle("FW hits");
        hMDCtrk_FWhit->GetXaxis()->SetTitleSize(0.06);
        hMDCtrk_FWhit->GetYaxis()->SetTitleSize(0.06);
        hMDCtrk_FWhit->GetXaxis()->SetLabelSize(0.04);
        hMDCtrk_FWhit->GetYaxis()->SetLabelSize(0.04);
        hMDCtrk_FWhit->Draw("colz");

        TLatex *l17=new TLatex(20,126,"PT2 trigger");
        l17->Draw();
	TLatex *l17_=new TLatex(30,100,"Au-Au, 1.23A GeV");
        l17_->Draw();

        c17->SaveAs("./picsFWtoFit/hMDCtrk_FWhit_PT2.C");
        c17->Print("./picsFWtoFit/hMDCtrk_FWhit_PT2.png");

	TCanvas *c18=new TCanvas("c18","",800,600);
        c18->cd();
        gPad->SetLogz();
	gStyle->SetOptStat(0);
        hMDCtrk_FWhit2->GetYaxis()->SetTitle("MDC tracks");
        hMDCtrk_FWhit2->GetXaxis()->SetTitle("FW hits");
        hMDCtrk_FWhit2->GetXaxis()->SetTitleSize(0.06);
        hMDCtrk_FWhit2->GetYaxis()->SetTitleSize(0.06);
        hMDCtrk_FWhit2->GetXaxis()->SetLabelSize(0.04);
        hMDCtrk_FWhit2->GetYaxis()->SetLabelSize(0.04);
        hMDCtrk_FWhit2->Draw("colz");

        TLatex *l18=new TLatex(20,126,"PT3 trigger");
        l18->Draw();
	TLatex *l18_=new TLatex(30,100,"Au-Au, 1.23A GeV");
        l18_->Draw();

        c18->SaveAs("./picsFWtoFit/hMDCtrk_FWhit_PT3.C");
        c18->Print("./picsFWtoFit/hMDCtrk_FWhit_PT3.png");


	TCanvas *c19=new TCanvas("c19","",800,600);
        c19->cd();
        gPad->SetLogz();
	gStyle->SetOptStat(0);
        hRPChit_FWcharge->GetYaxis()->SetTitle("RPC hits");
        hRPChit_FWcharge->GetXaxis()->SetTitle("FW charge, [GeV]");
        hRPChit_FWcharge->GetXaxis()->SetTitleSize(0.06);
        hRPChit_FWcharge->GetYaxis()->SetTitleSize(0.06);
        hRPChit_FWcharge->GetXaxis()->SetLabelSize(0.04);
        hRPChit_FWcharge->GetYaxis()->SetLabelSize(0.04);
        hRPChit_FWcharge->Draw("colz");

        TLatex *l19=new TLatex(6000,206,"PT2 trigger");
        l19->Draw();
	TLatex *l19_=new TLatex(8000,180,"Au-Au, 1.23A GeV");
        l19_->Draw();

        c19->SaveAs("./picsFWtoFit/hRPChit_FWcharge_PT2.C");
        c19->Print("./picsFWtoFit/hRPChit_FWcharge_PT2.png");

        TCanvas *c20=new TCanvas("c20","",800,600);
        c20->cd();
        gPad->SetLogz();
	gStyle->SetOptStat(0);
        hRPChit_FWcharge2->GetYaxis()->SetTitle("RPC hits");
        hRPChit_FWcharge2->GetXaxis()->SetTitle("FW charge, [GeV]");
        hRPChit_FWcharge2->GetXaxis()->SetTitleSize(0.06);
        hRPChit_FWcharge2->GetYaxis()->SetTitleSize(0.06);
        hRPChit_FWcharge2->GetXaxis()->SetLabelSize(0.04);
        hRPChit_FWcharge2->GetYaxis()->SetLabelSize(0.04);
        hRPChit_FWcharge2->Draw("colz");

        TLatex *l20=new TLatex(6000,206,"PT3 trigger");
        l20->Draw();
	TLatex *l20_=new TLatex(8000,180,"Au-Au, 1.23A GeV");
        l20_->Draw();

        c20->SaveAs("./picsFWtoFit/hRPChit_FWcharge_PT3.C");
        c20->Print("./picsFWtoFit/hRPChit_FWcharge_PT3.png");

        TCanvas *c21=new TCanvas("c21","",800,600);
        c21->cd();
        gPad->SetLogz();
	gStyle->SetOptStat(0);
        hTOFhit_FWcharge->GetYaxis()->SetTitle("TOF hits");
        hTOFhit_FWcharge->GetXaxis()->SetTitle("FW charge, [GeV]");
        hTOFhit_FWcharge->GetXaxis()->SetTitleSize(0.06);
        hTOFhit_FWcharge->GetYaxis()->SetTitleSize(0.06);
        hTOFhit_FWcharge->GetXaxis()->SetLabelSize(0.04);
        hTOFhit_FWcharge->GetYaxis()->SetLabelSize(0.04);
        hTOFhit_FWcharge->Draw("colz");

        TLatex *l21=new TLatex(6000,106,"PT2 trigger");
        l21->Draw();
	TLatex *l21_=new TLatex(8000,90,"Au-Au, 1.23A GeV");
        l21_->Draw();

        c21->SaveAs("./picsFWtoFit/hTOFhit_FWcharge_PT2.C");
        c21->Print("./picsFWtoFit/hTOFhit_FWcharge_PT2.png");


        TCanvas *c22=new TCanvas("c22","",800,600);
        c22->cd();
        gPad->SetLogz(); 
	gStyle->SetOptStat(0);
        hTOFhit_FWcharge2->GetYaxis()->SetTitle("TOF hits");
        hTOFhit_FWcharge2->GetXaxis()->SetTitle("FW charge, [GeV]");
        hTOFhit_FWcharge2->GetXaxis()->SetTitleSize(0.06);
        hTOFhit_FWcharge2->GetYaxis()->SetTitleSize(0.06);
        hTOFhit_FWcharge2->GetXaxis()->SetLabelSize(0.04);
        hTOFhit_FWcharge2->GetYaxis()->SetLabelSize(0.04);
        hTOFhit_FWcharge2->Draw("colz");

        TLatex *l22=new TLatex(6000,106,"PT3 trigger");
        l22->Draw();
	TLatex *l22_=new TLatex(8000,90,"Au-Au, 1.23A GeV");
        l22_->Draw();

        c22->SaveAs("./picsFWtoFit/hTOFhit_FWcharge_PT3.C");
        c22->Print("./picsFWtoFit/hTOFhit_FWcharge_PT3.png");

	TCanvas *c23=new TCanvas("c23","",800,600);
        c23->cd();
        gPad->SetLogz();
	gStyle->SetOptStat(0);
        hMDCtrk_FWcharge->GetYaxis()->SetTitle("MDC tracks");
        hMDCtrk_FWcharge->GetXaxis()->SetTitle("FW charge, [GeV]");
        hMDCtrk_FWcharge->GetXaxis()->SetTitleSize(0.06);
        hMDCtrk_FWcharge->GetYaxis()->SetTitleSize(0.06);
        hMDCtrk_FWcharge->GetXaxis()->SetLabelSize(0.04);
        hMDCtrk_FWcharge->GetYaxis()->SetLabelSize(0.04);
        hMDCtrk_FWcharge->Draw("colz");

        TLatex *l23=new TLatex(6000,126,"PT2 trigger");
        l23->Draw();
	TLatex *l23_=new TLatex(8000,100,"Au-Au, 1.23A GeV");
        l23_->Draw();

        c23->SaveAs("./picsFWtoFit/hMDCtrk_FWcharge_PT2.C");
        c23->Print("./picsFWtoFit/hMDCtrk_FWcharge_PT2.png");

        TCanvas *c24=new TCanvas("c24","",800,600);
        c24->cd();
        gPad->SetLogz();
	gStyle->SetOptStat(0);
        hMDCtrk_FWcharge2->GetYaxis()->SetTitle("MDC tracks");
        hMDCtrk_FWcharge2->GetXaxis()->SetTitle("FW charge, [GeV]");
        hMDCtrk_FWcharge2->GetXaxis()->SetTitleSize(0.06);
        hMDCtrk_FWcharge2->GetYaxis()->SetTitleSize(0.06);
        hMDCtrk_FWcharge2->GetXaxis()->SetLabelSize(0.04);
        hMDCtrk_FWcharge2->GetYaxis()->SetLabelSize(0.04);
        hMDCtrk_FWcharge2->Draw("colz");

        TLatex *l24=new TLatex(6000,126,"PT3 trigger");
        l24->Draw();
	TLatex *l24_=new TLatex(8000,100,"Au-Au, 1.23A GeV");
        l24_->Draw();

        c24->SaveAs("./picsFWtoFit/hMDCtrk_FWcharge_PT3.C");
        c24->Print("./picsFWtoFit/hMDCtrk_FWcharge_PT3.png");


	 TreeFile->cd();

        hFWhit->Write();
        hTOFhit->Write();
        hRPChit->Write();
        hMDCtrk->Write();
        hFWcharge->Write();
        hRPChit_FWhit->Write();
        hTOFhit_FWhit->Write();
        hMDCtrk_FWhit->Write();
        hRPChit_FWcharge->Write();
        hTOFhit_FWcharge->Write();
        hMDCtrk_FWcharge->Write();
        hFWhit2->Write();
        hTOFhit2->Write();
        hRPChit2->Write();
        hMDCtrk2->Write();
        hFWcharge2->Write();
        hRPChit_FWhit2->Write();
        hTOFhit_FWhit2->Write();
        hMDCtrk_FWhit2->Write();
        hRPChit_FWcharge2->Write();
        hTOFhit_FWcharge2->Write();
        hMDCtrk_FWcharge2->Write();
        hFWhit_Cut->Write();
        hTOFhit_Cut->Write();
        hRPChit_Cut->Write();
        hMDCtrk_Cut->Write();
        hFWcharge_Cut->Write();
        hRPChit_FWhit_Cut->Write();
        hTOFhit_FWhit_Cut->Write();
        hMDCtrk_FWhit_Cut->Write();
        hRPChit_FWcharge_Cut->Write();
        hTOFhit_FWcharge_Cut->Write();
        hMDCtrk_FWcharge_Cut->Write();
        hFWhit2_Cut->Write();
        hTOFhit2_Cut->Write();
        hRPChit2_Cut->Write();
        hMDCtrk2_Cut->Write();
        hFWcharge2_Cut->Write();
        hRPChit_FWhit2_Cut->Write();
        hTOFhit_FWhit2_Cut->Write();
        hMDCtrk_FWhit2_Cut->Write();
        hRPChit_FWcharge2_Cut->Write();
        hTOFhit_FWcharge2_Cut->Write();
        hMDCtrk_FWcharge2_Cut->Write();



        TreeFile->Close();


/*
	TCanvas *c01=new TCanvas("c01");
	c01->cd();
	gPad->SetLogy();

	hFWhit_ring1->GetXaxis()->SetTitle("FW hits");
	hFWhit_ring1->GetYaxis()->SetTitle("Counts");
	hFWhit_ring1->Draw();

	c01->SaveAs("./picsFWtoFit/FWhit_ring1.C");
	c01->Print("./picsFWtoFit/FWhit_ring1.png");


	 TCanvas *c02=new TCanvas("c02");
        c02->cd();
        gPad->SetLogy();

        hFWhit_ring12->GetXaxis()->SetTitle("FW hits");
        hFWhit_ring12->GetYaxis()->SetTitle("Counts");
        hFWhit_ring12->Draw();

        c02->SaveAs("./picsFWtoFit/FWhit_ring12.C");
        c02->Print("./picsFWtoFit/FWhit_ring12.png");


	 TCanvas *c03=new TCanvas("c03");
        c03->cd();
        gPad->SetLogy();

        hFWhit_ring13->GetXaxis()->SetTitle("FW hits");
        hFWhit_ring13->GetYaxis()->SetTitle("Counts");
        hFWhit_ring13->Draw();

        c03->SaveAs("./picsFWtoFit/FWhit_ring13.C");
        c03->Print("./picsFWtoFit/FWhit_ring13.png");


	 TCanvas *c04=new TCanvas("c04");
        c04->cd();
        gPad->SetLogy();

        hFWhit_ring14->GetXaxis()->SetTitle("FW hits");
        hFWhit_ring14->GetYaxis()->SetTitle("Counts");
        hFWhit_ring14->Draw();

        c04->SaveAs("./picsFWtoFit/FWhit_ring14.C");
        c04->Print("./picsFWtoFit/FWhit_ring14.png");


	 TCanvas *c05=new TCanvas("c05");
        c05->cd();
        gPad->SetLogy();

        hFWhit_ring56->GetXaxis()->SetTitle("FW hits");
        hFWhit_ring56->GetYaxis()->SetTitle("Counts");
        hFWhit_ring56->Draw();

        c05->SaveAs("./picsFWtoFit/FWhit_ring56.C");
        c05->Print("./picsFWtoFit/FWhit_ring56.png");


	 TCanvas *c06=new TCanvas("c06");
        c06->cd();
        gPad->SetLogy();

        hFWhit_ring57->GetXaxis()->SetTitle("FW hits");
        hFWhit_ring57->GetYaxis()->SetTitle("Counts");
        hFWhit_ring57->Draw();

        c06->SaveAs("./picsFWtoFit/FWhit_ring57.C");
        c06->Print("./picsFWtoFit/FWhit_ring57.png");


	 TCanvas *c07=new TCanvas("c07");
        c07->cd();
        gPad->SetLogy();

        hFWhit_ring58->GetXaxis()->SetTitle("FW hits");
        hFWhit_ring58->GetYaxis()->SetTitle("Counts");
        hFWhit_ring58->Draw();

        c07->SaveAs("./picsFWtoFit/FWhit_ring58.C");
        c07->Print("./picsFWtoFit/FWhit_ring58.png");


	 TCanvas *c08=new TCanvas("c08");
        c08->cd();
        gPad->SetLogy();

        hFWhit_ring59->GetXaxis()->SetTitle("FW hits");
        hFWhit_ring59->GetYaxis()->SetTitle("Counts");
        hFWhit_ring59->Draw();

        c08->SaveAs("./picsFWtoFit/FWhit_ring59.C");
        c08->Print("./picsFWtoFit/FWhit_ring59.png");

*/
/*
	char tr[50];
	char name4[200]={"PT2 trigger"};
	char name5[200]={"PT3 trigger"};

	TCanvas *c09=new TCanvas("c09");
        c09->cd();
        gPad->SetLogy();

	hFWhit->GetXaxis()->SetTitle("FW hits");
	hFWhit->GetYaxis()->SetTitle("Counts");
//	hFWhit->Scale(8);
	hFWhit->SetLineColor(2);
	hFWhit2->SetLineColor(4);
	hFWhit->Draw();
	hFWhit2->Draw("same");

	TLegend *leg03 = new TLegend(0.2, 0.15, 0.6, 0.4);
        leg03->SetFillColor(0);
        leg03->SetBorderSize(0);
        leg03->SetTextSize(0.03);
        leg03->SetTextFont(42);

	sprintf(tr, "%s", name4);
        leg03->AddEntry(hFWhit, tr, "l");
        sprintf(tr, "%s", name5);
        leg03->AddEntry(hFWhit2, tr, "l");

	leg03->Draw();
        c09->Print("./picsFWtoFit/FWhits_DiffTrigger.png");
        c09->SaveAs("./picsFWtoFit/FWhits_DiffTrigger.C","RECREATE");

	

	 TCanvas *c10=new TCanvas("c10");
        c10->cd();
        gPad->SetLogy();

        MultTOF_All->GetXaxis()->SetTitle("TOF hits");
        MultTOF_All->GetYaxis()->SetTitle("Counts");
   
	MultTOF_All->SetLineColor(2);
        MultTOF_All->Draw();
        MultTOF_All->Scale(8);
        MultTOF_All2->SetLineColor(4);
        MultTOF_All2->Draw("same");


	TLegend *leg10 = new TLegend(0.2, 0.15, 0.6, 0.4);
        leg10->SetFillColor(0);
        leg10->SetBorderSize(0);
        leg10->SetTextSize(0.03);
        leg10->SetTextFont(42);

        sprintf(tr, "%s", name4);
        leg10->AddEntry(MultTOF_All, tr, "l");
        sprintf(tr, "%s", name5);
        leg10->AddEntry(MultTOF_All2, tr, "l");

        leg10->Draw();


        c10->SaveAs("./picsFWtoFit/TOFhit_PTtr.C");
        c10->Print("./picsFWtoFit/TOFhit_PTtr.png");


	TCanvas *c11=new TCanvas("c11");
        c11->cd();
        gPad->SetLogz();

	hTOFhit_FWhit->GetXaxis()->SetTitle("FW hits");
	hTOFhit_FWhit->GetYaxis()->SetTitle("TOF hits");
	hTOFhit_FWhit->Draw("colz");

	TLatex *l1=new TLatex(20,106, "PT2 trigger");
	l1->Draw();

	c11->SaveAs("./picsFWtoFit/TOF_FWhits_PT2.C");
	c11->Print("./picsFWtoFit/TOF_FWhits_PT2.png");


	 TCanvas *c12=new TCanvas("c12");
        c12->cd();
        gPad->SetLogz();

        hTOFhit_FWhit2->GetXaxis()->SetTitle("FW hits");
        hTOFhit_FWhit2->GetYaxis()->SetTitle("TOF hits");
        hTOFhit_FWhit2->Draw("colz");

	TLatex *l2=new TLatex(20,106, "PT3 trigger");
        l2->Draw();

        c12->SaveAs("./picsFWtoFit/TOF_FWhits_PT3.C");
        c12->Print("./picsFWtoFit/TOF_FWhits_PT3.png");




*/




}
