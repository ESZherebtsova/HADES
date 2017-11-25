#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
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

void Histo() {
cout<<"DEbug1"<<endl;
//TFile *file = new TFile("hades_fullstat.root", "read");
//TTree *tree1 = (TTree*)file->Get("tree");
TChain *tree1=new TChain("tree");
tree1->Add("tree_12108160806.root");
//TH1F *MultTOF=new TH1F("MultTOF", "MultTOF", 120,0,120);
//TH1F *MultTOF_NoCuts=new TH1F("MultTOF_NoCuts", "MultTOF_NoCuts", 120,0,120);
TH1F *FW=new TH1F("FW", "FW", 1500,0,15000);
TH1F *FW_NoCuts=new TH1F("FW_NoCuts", "FW_NoCuts", 300,0,30000);
//TH2F *vX_vY=new TH2F("vX_vY", "vX_vY", 2500,-100,150,2500,-100,250);
//TH2F *vX_vY_NoCuts=new TH2F("vX_vY_NoCuts", "vX_vY_NoCuts", 2500,-100,150,2500,-100,250);
//TH1F *vY=new TH1F("vY", "vY", 200,0,20000);
//TH1F *hvZ=new TH1F("hvZ", "hvZ", 100,-80,20);
//TH1F *vZ_NoCuts=new TH1F("vZ_NoCuts", "vZ_NoCuts", 100,-80,20);

TH2F *FW_VertexZ=new TH2F("FW_VertexZ", "",1000,-80,20, 150,0,15000);
TH2F *FW_VertexZ_NoCuts=new TH2F("FW_VertexZ_NoCuts", "",1000,-80,20, 150,0,15000);
TH2F *MultTOF_FW=new TH2F("MultTOF_FW", "",120,0,120,150,0,15000);

//TH2F *MultTOF_VertexZ=new TH2F("MultTOF_VertexZ", "",1000,-80,20, 120,0,120);
TH1F *Sum_TOF_RPC=new TH1F("Sum_TOF_RPC", "", 250,0,250);
TH1F *Sum_TOF_RPC_Cut=new TH1F("Sum_TOF_RPC_Cut", "", 250,0,250);
TH1F *Sum_TOF_RPC_clean=new TH1F("Sum_TOF_RPC_clean", "", 250,0,250);


TH2F *MultTOFRPC_FW_Cut=new TH2F("MultTOFRPC_FW_Cut", "",250,0,250,150,0,15000);
TH2F *MultTOFRPC_FW=new TH2F("MultTOFRPC_FW", "",250,0,250,150,0,15000);
TH2F *MultTOFRPC_FW_No=new TH2F("MultTOFRPC_FW_No", "",250,0,250,150,0,15000);
TH2F *MultTOF_FW_NoCuts=new TH2F("MultTOF_FW_NoCuts", "",120,0,120,200,0,20000);
//TH2F *MultTOF_VertexZ_NoCuts=new TH2F("MultTOF_VertexZ_NoCuts", "",1000,-80,20, 120,0,120);
//TH1F *Sum_TOF_RPC_NoCuts=new TH1F("Sum_TOF_RPC_NoCuts", "", 400,0,400);

TH1F *hTracks=new TH1F("hTracks", "", 120,0,120);
TH1F *hTracks_EtaCut=new TH1F("hTracks_EtaCut", "", 120,0,120);

TH2F *hEta_Pt=new TH2F("hEta_Pt", "",160,0.,1.6,2200,0,2200);

TF1 *tf1=new TF1("tf1","-4000./150.*x+4000",0,150);
TF1 *tf2=new TF1("tf2","-50*x+13500",70,250);

TH2F *MultTOFMDC_FW=new TH2F("MultTOFMDC_FW", "",250,0,250,150,0,15000);
TH2F *MultMDC_FW=new TH2F("MultMDC_FW", "",120,0,120,150,0,15000);

TH2F *MultTOFMDC_FW_EtaCut=new TH2F("MultTOFMDC_FW_EtaCut", "",250,0,250,150,0,15000);
TH2F *MultMDC_FW_EtaCut=new TH2F("MultMDC_FW_EtaCut", "",120,0,120,150,0,15000);

TH2F *MultTOFMDC_FW_No=new TH2F("MultTOFMDC_FW_No", "",250,0,250,150,0,15000);
TH2F *MultMDC_FW_No=new TH2F("MultMDC_FW_No", "",120,0,120,150,0,15000);

TH2F *FWhits_MDC_EtaCut=new TH2F("FWhits_MDC_EtaCut", "",120,0,120,140,0,140);
TH2F *MultMDC_TOFMDC_EtaCut=new TH2F("MultMDC_TOFMDC_EtaCut", "",120,0,120,200,0,200);

TH2F *FWhits_MDC=new TH2F("FWhits_MDC", "",120,0,120,140,0,140);
TH2F *MultMDC_TOFMDC=new TH2F("MultMDC_TOFMDC", "",120,0,120,200,0,200);

TH2F *heta_vs_phi=new TH2F("heta_vs_phi","",160,0,1.6,628,0,6.28);
TH2F *heta_vs_phi2=new TH2F("heta_vs_phi2","",160,0,1.6,628,0,6.28);
TFile* TreeFile = new TFile("Histos_.root","RECREATE");
	
	float Eta_neg, Eta_pos, Phi_pos, Phi_neg;
        short nTracks,nTofHitsCut;
        float vZ,vX,vY,vChi2;
        short nRpcClustCut;
        float SumTofRpc,SumTofMdc;
        short wallChargeTot;
	float pt[200];
	float theta[200];
	float k1,k2,b1,b2,Xcoor,Xcoor2;	
	float Eta, Pt;
	short nWallHitsTot;
	short nMdcHits[200];
	short MDChits;
	float phi[200];
	short charge[200];
	short Charge;
	float Phi;
	tree1->SetBranchAddress("charge", &charge);
	tree1->SetBranchAddress("phi", &phi);
        tree1->SetBranchAddress("nTofHitsCut", &nTofHitsCut);
	tree1->SetBranchAddress("nTracks", &nTracks);
 	tree1->SetBranchAddress("vZ", &vZ);
        tree1->SetBranchAddress("vX", &vX);
        tree1->SetBranchAddress("vY", &vY);
        tree1->SetBranchAddress("wallChargeTot", &wallChargeTot);
        tree1->SetBranchAddress("nRpcClustCut",&nRpcClustCut);
        tree1->SetBranchAddress("vChi2", &vChi2);
	tree1->SetBranchAddress("pt", &pt);
	tree1->SetBranchAddress("theta", &theta);
	tree1->SetBranchAddress("nWallHitsTot", &nWallHitsTot);
	tree1->SetBranchAddress("nMdcHits", &nMdcHits);
	Int_t count=0;
	int number_tracks;
	int entry=0;
        while(entry < tree1->GetEntries()) {
                tree1->GetEntry(entry);
            
		SumTofRpc=nTofHitsCut+nRpcClustCut;
		MultTOFRPC_FW_No->Fill(SumTofRpc,wallChargeTot);
		MultTOF_FW_NoCuts->Fill(nTofHitsCut,wallChargeTot);
		MultMDC_FW_No->Fill(nTracks,wallChargeTot);
		MultTOFMDC_FW_No->Fill(SumTofMdc,wallChargeTot);
	if (vZ>=-60 && vZ<=0 && (pow(vX*vX+vY*vY,0.5)<3) && vChi2>0.5 && vChi2<22) {

				
/*	k1=-4000./150.;
	b1=4000.;
	Xcoor=(wallChargeTot-b1)/k1;

	k2=-50;

	b2=13500;

	Xcoor2=(wallChargeTot-b2)/k2;

	SumTofRpc=nTofHitsCut+nRpcClustCut;
	MultTOFRPC_FW->Fill(SumTofRpc,wallChargeTot); 
	Sum_TOF_RPC->Fill(SumTofRpc);	
*/
//	cout<<"X coor = "<<Xcoor<<" X coor 2 = "<<Xcoor2<<" SumTofRpc = "<<SumTofRpc<<endl;

	
/*if (wallChargeTot>100 && SumTofRpc<242 &&  ((wallChargeTot>tf1->Eval(SumTofRpc)) || (SumTofRpc>Xcoor)) && ((wallChargeTot<tf2->Eval(SumTofRpc)) || (SumTofRpc<Xcoor2))) {

		Sum_TOF_RPC_clean->Fill(SumTofRpc);
	if (SumTofRpc<242)	Sum_TOF_RPC_Cut->Fill(SumTofRpc);

		 
		MultTOFRPC_FW_Cut->Fill(SumTofRpc,wallChargeTot);

		FW->Fill(wallChargeTot);
		MultTOF_FW->Fill(nTofHitsCut,wallChargeTot);
		MultMDC_FW->Fill(nTracks,wallChargeTot);
		MultTOFMDC_FW->Fill(SumTofMdc,wallChargeTot);
	
*/
//count=0;
	for (int i=0;i<nTracks;i++) {

Eta=theta[i];
Pt=pt[i];
MDChits=nMdcHits[i];
Phi=phi[i];
Charge=charge[i];
if (Charge>0) { Phi_pos=phi[i];  Eta_pos=theta[i]; } 
if (Charge<0) { Phi_neg=phi[i];  Eta_neg=theta[i]; }


heta_vs_phi->Fill(Eta_pos,Phi_pos);
heta_vs_phi2->Fill(Eta_neg,Phi_neg);

/*                 if (Eta>0.2 && Eta<0.4) {
hEta_Pt->Fill(Pt,Eta);
//cout<<" Eta = "<<Eta<<" Pt = "<<Pt<<" MDChits = "<<MDChits<<endl;
        count++;
      SumTofMdc=MDChits+nTofHitsCut;
        MultTOFMDC_FW_EtaCut->Fill(SumTofMdc,wallChargeTot);
        MultMDC_FW_EtaCut->Fill(nTracks,wallChargeTot);
        FWhits_MDC_EtaCut->Fill(nTracks,nWallHitsTot);
        MultMDC_TOFMDC_EtaCut->Fill(nTracks,SumTofMdc);
        hTracks_EtaCut->Fill(nTracks);

                                }*/
                        }
/*number_tracks=count;
SumTofMdc=MDChits+nTofHitsCut;
        MultTOFMDC_FW_EtaCut->Fill(SumTofMdc,wallChargeTot);
        MultMDC_FW_EtaCut->Fill(number_tracks,wallChargeTot);
        FWhits_MDC_EtaCut->Fill(number_tracks,nWallHitsTot);
        MultMDC_TOFMDC_EtaCut->Fill(number_tracks,SumTofMdc);
        hTracks_EtaCut->Fill(number_tracks);


count=0;*/

			MultTOFRPC_FW_Cut->Fill(SumTofRpc,wallChargeTot);

                FW->Fill(wallChargeTot);
                MultTOF_FW->Fill(nTofHitsCut,wallChargeTot);
                MultMDC_FW->Fill(nTracks,wallChargeTot);
                MultTOFMDC_FW->Fill(SumTofMdc,wallChargeTot);

		}

		FWhits_MDC->Fill(nTracks,nWallHitsTot);
		MultMDC_TOFMDC->Fill(nTracks,SumTofMdc);
 //             MultTOF->Fill(nTofHitsCut);
               // Sum_TOF_RPC->Fill(SumTofRpc);
      //      	MultTOF_VertexZ->Fill(vZ,nTofHitsCut);
        //   	FW_VertexZ->Fill(vZ,wallChargeTot);
            //	FW->Fill(wallChargeTot);
	//	vX_vY->Fill(vX,vY);
	//	hvZ->Fill(vZ);
		hTracks->Fill(nTracks);
		MultTOFRPC_FW->Fill(SumTofRpc,wallChargeTot);
	}*/ //end cut event
		
	/*	MultTOF_NoCuts->Fill(nTofHitsCut);	
	//	MultTOFRPC_FW_No->Fill(SumTofRpc,wallChargeTot);
		FW_NoCuts->Fill(wallChargeTot);
	//	vX_vY_NoCuts->Fill(vX,vY);
	//	vZ_NoCuts->Fill(vZ);
		 FW_VertexZ_NoCuts->Fill(vZ,wallChargeTot);	
	//	MultTOF_FW_NoCuts->Fill(nTofHitsCut35,wallChargeTot);
	//	Sum_TOF_RPC_NoCuts->Fill(SumTofRpc);
	//	MultTOF_VertexZ_NoCuts->Fill(vZ,nTofHitsCut);
          */
		       entry++;

        }


cout<<" DEBUG 22"<<endl;
/*TFile *filerr = new TFile("MultTOFRPC_FW_50M_test.root", "RECREATE");
        filerr->cd();
        MultTOFRPC_FW->Write();
        filerr->Close();

TFile *filerr2 = new TFile("MultMDC_FW_50M_test.root", "RECREATE");
        filerr2->cd();
        MultMDC_FW->Write();
        filerr2->Close();

*/
TFile *file3 = new TFile("Sum_TOF_RPC_5M.root", "RECREATE");
        file3->cd();
        Sum_TOF_RPC->Write();
        file3->Close();

TFile *file4 = new TFile("Sum_TOF_RPC_Cut_5M.root", "RECREATE");
        file4->cd();
        Sum_TOF_RPC_Cut->Write();
        file4->Close();

TFile *file5 = new TFile("Sum_TOF_RPC_clean_5M.root", "RECREATE");
        file5->cd();
        Sum_TOF_RPC_clean->Write();
        file5->Close();
/*
TFile *file4 = new TFile("Charge_FW_50M_Cut2.root", "RECREATE");
        file4->cd();
        FW->Write();
        file4->Close();

TFile *file5 = new TFile("Mult_FW_50M_No.root", "RECREATE");
        file5->cd();
        MultTOFRPC_FW_No->Write();
        file5->Close();
*/
char tr[50];
char name1[50] = { "Before cuts" };
char name2[50] = { "After cuts" };


TCanvas *fEta_Phi = new TCanvas("fEta_Phi");
        fEta_Phi ->cd();
        gPad-> SetLogz();
        heta_vs_phi->GetXaxis()->SetTitle("#eta");
        heta_vs_phi->GetYaxis()->SetTitle("#phi, [rad]");
        heta_vs_phi->Draw("COLZ");

        fEta_Phi->Print("heta_vs_phi.png");
        fEta_Phi->SaveAs("heta_vs_phi.C","RECREATE");

TCanvas *fEta_Phi2 = new TCanvas("fEta_Phi2");
        fEta_Phi2 ->cd();
        gPad-> SetLogz();
        heta_vs_phi2->GetXaxis()->SetTitle("#eta");
        heta_vs_phi2->GetYaxis()->SetTitle("#phi, [rad]");
        heta_vs_phi2->Draw("COLZ");

        fEta_Phi2->Print("heta_vs_phi2.png");
        fEta_Phi2->SaveAs("heta_vs_phi2.C","RECREATE");


TCanvas *fFW = new TCanvas("fFW");
	fFW->cd();
	gPad-> SetLogy();
	FW->SetLineColor(2);	
	FW_NoCuts->SetLineColor(4);
	FW->GetXaxis()->SetTitle("FW charge, [GeV]");
	FW->GetYaxis()->SetTitle("N_{events}");


FW->GetXaxis()->SetTitleSize(0.06);
FW->GetYaxis()->SetTitleSize(0.06);
FW->GetXaxis()->SetLabelSize(0.04);
FW->GetYaxis()->SetLabelSize(0.04);


	FW->Draw();
	FW_NoCuts->Draw("same");

	TLegend *leg2 = new TLegend(0.2, 0.15, 0.6, 0.4);
	leg2->SetFillColor(0);
	leg2->SetBorderSize(0);
	leg2->SetTextSize(0.03);
	leg2->SetTextFont(42);
	sprintf(tr, "%s", name1);
	leg2->AddEntry(FW_NoCuts, tr, "l"); 
	sprintf(tr, "%s", name2);
	leg2->AddEntry(FW, tr, "l");	
	leg2->Draw();

	fFW->Print("FW_DoPosle.png");
	fFW->SaveAs("FW_DoPosle.C","RECREATE");
/*
TCanvas *fvZ = new TCanvas("fvZ");
	fvZ->cd();
	gPad-> SetLogy();
	hvZ->SetLineColor(2);	
	vZ_NoCuts->SetLineColor(4);
	hvZ->GetXaxis()->SetTitle("z_{vertex}, [cm]");
	hvZ->GetYaxis()->SetTitle("N_{events}");
	hvZ->Draw();
	vZ_NoCuts->Draw("same");

	TLegend *leg1 = new TLegend(0.2, 0.15, 0.6, 0.4);
	leg1->SetFillColor(0);
	leg1->SetBorderSize(0);
	leg1->SetTextSize(0.03);
	leg1->SetTextFont(42);
	sprintf(tr, "%s", name1);
	leg1->AddEntry(vZ_NoCuts, tr, "l"); 
	sprintf(tr, "%s", name2);
	leg1->AddEntry(hvZ, tr, "l");	
	leg1->Draw();

	fvZ->Print("vZ_DoPosle.png");
	fvZ->SaveAs("vZ_DoPosle.C","RECREATE");

TCanvas *fMultTOF = new TCanvas("fMultTOF");
	fMultTOF->cd();
	gPad-> SetLogy();
	MultTOF->SetLineColor(2);	
	MultTOF_NoCuts->SetLineColor(4);
	MultTOF->GetXaxis()->SetTitle("TOF M_{trk}");
	MultTOF->GetYaxis()->SetTitle("N_{events}");
	MultTOF->Draw();
	MultTOF_NoCuts->Draw("same");

	TLegend *leg = new TLegend(0.2, 0.15, 0.6, 0.4);
	leg->SetFillColor(0);
	leg->SetBorderSize(0);
	leg->SetTextSize(0.03);
	leg->SetTextFont(42);
	sprintf(tr, "%s", name1);
	leg->AddEntry(MultTOF_NoCuts, tr, "l"); 
	sprintf(tr, "%s", name2);
	leg->AddEntry(MultTOF, tr, "l");	
	leg->Draw();

	fMultTOF->Print("MultTOF_DoPosle.png");
	fMultTOF->SaveAs("MultTOF_DoPosle.C","RECREATE");

TCanvas *fvX_vY = new TCanvas("fvX_vY");
	fvX_vY->cd();
	gPad-> SetLogz();
	vX_vY->GetXaxis()->SetTitle("x_{vertex}, [cm]");
	vX_vY->GetYaxis()->SetTitle("y_{vertex}, [cm]");
	vX_vY->Draw("COLZ");

	fvX_vY->Print("vX_vY_Posle.png");
	fvX_vY->SaveAs("vX_vY_Posle.C","RECREATE");

TCanvas *fMultTOFRPC_FW = new TCanvas("fMultTOFRPC_FW");
        fMultTOFRPC_FW->cd();
        gPad-> SetLogz();
        MultTOFRPC_FW->GetXaxis()->SetTitle("TOF+RPC M_{trk}");
        MultTOFRPC_FW->GetYaxis()->SetTitle("FW charge, [GeV]");
        MultTOFRPC_FW->Draw("COLZ");

        fMultTOFRPC_FW->Print("MultTOFRPC_FW_Posle.png");
        fMultTOFRPC_FW->SaveAs("MultTOFRPC_FW_Posle.C","RECREATE");


TCanvas *fvX_vY_NoCuts = new TCanvas("fvX_vY_NoCuts");
	fvX_vY_NoCuts->cd();
	gPad-> SetLogz();
	vX_vY_NoCuts->GetXaxis()->SetTitle("x_{vertex}, [cm]");
	vX_vY_NoCuts->GetYaxis()->SetTitle("y_{vertex}, [cm]");
	vX_vY_NoCuts->Draw("COLZ");

	fvX_vY_NoCuts->Print("vX_vY_Do.png");
	fvX_vY_NoCuts->SaveAs("vX_vY_Do.C","RECREATE");

TCanvas *fEtaPt = new TCanvas("fEtaPt");
        fEtaPt->cd();
        gPad-> SetLogz();
        hEta_Pt->GetXaxis()->SetTitle("p_{T}, [Gev/c]");
        hEta_Pt->GetYaxis()->SetTitle("#eta");
        hEta_Pt->GetXaxis()->SetTitleSize(0.06);
hEta_Pt->GetYaxis()->SetTitleSize(0.06);
hEta_Pt->GetXaxis()->SetLabelSize(0.04);
hEta_Pt->GetYaxis()->SetLabelSize(0.04);

        hEta_Pt->Draw("COLZ");

        fEtaPt->Print("hEta_Pt.png");
        fEtaPt->SaveAs("Eta_Pt.C","RECREATE");


TCanvas *fFWhits_MDC = new TCanvas("fFWhits_MDC");
        fFWhits_MDC->cd();
        gPad-> SetLogz();
        FWhits_MDC->GetXaxis()->SetTitle("MDC tracks");
        FWhits_MDC->GetYaxis()->SetTitle("FW hits");
        FWhits_MDC->GetXaxis()->SetTitleSize(0.06);
FWhits_MDC->GetYaxis()->SetTitleSize(0.06);
FWhits_MDC->GetXaxis()->SetLabelSize(0.04);
FWhits_MDC->GetYaxis()->SetLabelSize(0.04);

        FWhits_MDC->Draw("COLZ");

        fFWhits_MDC->Print("FWhits_MDC.png");
        fFWhits_MDC->SaveAs("FWhits_MDC.C","RECREATE");


TCanvas *fMultMDC_TOFMDC = new TCanvas("fMultMDC_TOFMDC");
        fMultMDC_TOFMDC->cd();
        gPad-> SetLogz();
        MultMDC_TOFMDC->GetXaxis()->SetTitle("MDC tracks");
        MultMDC_TOFMDC->GetYaxis()->SetTitle("TOF+MDC hits");
        MultMDC_TOFMDC->GetXaxis()->SetTitleSize(0.06);
MultMDC_TOFMDC->GetYaxis()->SetTitleSize(0.06);
MultMDC_TOFMDC->GetXaxis()->SetLabelSize(0.04);
MultMDC_TOFMDC->GetYaxis()->SetLabelSize(0.04);

        MultMDC_TOFMDC->Draw("COLZ");

        fMultMDC_TOFMDC->Print("MultMDC_TOFMDC.png");
        fMultMDC_TOFMDC->SaveAs("MultMDC_TOFMDC.C","RECREATE");



TCanvas *fFWhits_MDC_EtaCut = new TCanvas("fFWhits_MDC_EtaCut");
        fFWhits_MDC_EtaCut->cd();
        gPad-> SetLogz();
        FWhits_MDC_EtaCut->GetXaxis()->SetTitle("MDC tracks");
        FWhits_MDC_EtaCut->GetYaxis()->SetTitle("FW hits");
        FWhits_MDC_EtaCut->GetXaxis()->SetTitleSize(0.06);
FWhits_MDC_EtaCut->GetYaxis()->SetTitleSize(0.06);
FWhits_MDC_EtaCut->GetXaxis()->SetLabelSize(0.04);
FWhits_MDC_EtaCut->GetYaxis()->SetLabelSize(0.04);

        FWhits_MDC_EtaCut->Draw("COLZ");

        fFWhits_MDC_EtaCut->Print("FWhits_MDC_EtaCut.png");
        fFWhits_MDC_EtaCut->SaveAs("FWhits_MDC_EtaCut.C","RECREATE");


TCanvas *fMultMDC_TOFMDC_EtaCut = new TCanvas("fMultMDC_TOFMDC_EtaCut");
        fMultMDC_TOFMDC_EtaCut->cd();
        gPad-> SetLogz();
        MultMDC_TOFMDC_EtaCut->GetXaxis()->SetTitle("MDC tracks");
        MultMDC_TOFMDC_EtaCut->GetYaxis()->SetTitle("TOF+MDC hits");
        MultMDC_TOFMDC_EtaCut->GetXaxis()->SetTitleSize(0.06);
MultMDC_TOFMDC_EtaCut->GetYaxis()->SetTitleSize(0.06);
MultMDC_TOFMDC_EtaCut->GetXaxis()->SetLabelSize(0.04);
MultMDC_TOFMDC_EtaCut->GetYaxis()->SetLabelSize(0.04);

        MultMDC_TOFMDC_EtaCut->Draw("COLZ");

        fMultMDC_TOFMDC_EtaCut->Print("MultMDC_TOFMDC_EtaCut.png");
        fMultMDC_TOFMDC_EtaCut->SaveAs("MultMDC_TOFMDC_EtaCut.C","RECREATE");


TCanvas *fFW_VertexZ_NoCuts = new TCanvas("fFW_VertexZ_NoCuts");
	fFW_VertexZ_NoCuts->cd();
	gPad-> SetLogz();
	FW_VertexZ_NoCuts->GetXaxis()->SetTitle("z_{vertex}, [mm]");
	FW_VertexZ_NoCuts->GetYaxis()->SetTitle("FW charge, [GeV]");
	FW_VertexZ_NoCuts->GetXaxis()->SetTitleSize(0.06);
FW_VertexZ_NoCuts->GetYaxis()->SetTitleSize(0.06);
FW_VertexZ_NoCuts->GetXaxis()->SetLabelSize(0.04);
FW_VertexZ_NoCuts->GetYaxis()->SetLabelSize(0.04);

	FW_VertexZ_NoCuts->Draw("COLZ");

	fFW_VertexZ_NoCuts->Print("FW_VertexZ_Do.png");
	fFW_VertexZ_NoCuts->SaveAs("FW_VertexZ_Do.C","RECREATE");


TCanvas *fFW_VertexZ = new TCanvas("fFW_VertexZ");
	fFW_VertexZ->cd();
	gPad-> SetLogz();
	FW_VertexZ->GetXaxis()->SetTitle("z_{vertex}, [mm]");
	FW_VertexZ->GetYaxis()->SetTitle("FW charge, [GeV]");
	FW_VertexZ->GetXaxis()->SetTitleSize(0.06);
FW_VertexZ->GetYaxis()->SetTitleSize(0.06);
FW_VertexZ->GetXaxis()->SetLabelSize(0.04);
FW_VertexZ->GetYaxis()->SetLabelSize(0.04);



	FW_VertexZ->Draw("COLZ");

	fFW_VertexZ->Print("FW_VertexZ_Posle.png");
	fFW_VertexZ->SaveAs("FW_VertexZ_Posle.C","RECREATE");

TCanvas *fMultTOFRPC_FW = new TCanvas("fMultTOFRPC_FW");
	fMultTOFRPC_FW->cd();
	gPad-> SetLogz();
	MultTOFRPC_FW->GetXaxis()->SetTitle("TOF+RPC hits");
	MultTOFRPC_FW->GetYaxis()->SetTitle("FW charge, [GeV]");
	MultTOFRPC_FW->GetXaxis()->SetTitleSize(0.06);
MultTOFRPC_FW->GetYaxis()->SetTitleSize(0.06);
MultTOFRPC_FW->GetXaxis()->SetLabelSize(0.04);
MultTOFRPC_FW->GetYaxis()->SetLabelSize(0.04);
	MultTOFRPC_FW->Draw("COLZ");

	fMultTOFRPC_FW->Print("MultTOFRPC_FW.png");
	fMultTOFRPC_FW->SaveAs("MultTOFRPC_FW.C","RECREATE");



TCanvas *fMultTOFMDC_FW = new TCanvas("fMultTOFMDC_FW");
        fMultTOFMDC_FW->cd();
        gPad-> SetLogz();
        MultTOFMDC_FW->GetXaxis()->SetTitle("TOF+MDC hits");
        MultTOFMDC_FW->GetYaxis()->SetTitle("FW charge, [GeV]");
        MultTOFMDC_FW->GetXaxis()->SetTitleSize(0.06);
MultTOFMDC_FW->GetYaxis()->SetTitleSize(0.06);
MultTOFMDC_FW->GetXaxis()->SetLabelSize(0.04);
MultTOFMDC_FW->GetYaxis()->SetLabelSize(0.04);
        MultTOFMDC_FW->Draw("COLZ");

        fMultTOFMDC_FW->Print("MultTOFMDC_FW.png");
        fMultTOFMDC_FW->SaveAs("MultTOFMDC_FW.C","RECREATE");

TCanvas *fMultTOFMDC_FW_EtaCut = new TCanvas("fMultTOFMDC_FW_EtaCut");
        fMultTOFMDC_FW_EtaCut->cd();
        gPad-> SetLogz();
        MultTOFMDC_FW_EtaCut->GetXaxis()->SetTitle("TOF+MDC hits");
        MultTOFMDC_FW_EtaCut->GetYaxis()->SetTitle("FW charge, [GeV]");
        MultTOFMDC_FW_EtaCut->GetXaxis()->SetTitleSize(0.06);
MultTOFMDC_FW_EtaCut->GetYaxis()->SetTitleSize(0.06);
MultTOFMDC_FW_EtaCut->GetXaxis()->SetLabelSize(0.04);
MultTOFMDC_FW_EtaCut->GetYaxis()->SetLabelSize(0.04);
        MultTOFMDC_FW_EtaCut->Draw("COLZ");

        fMultTOFMDC_FW_EtaCut->Print("MultTOFMDC_FW_EtaCut.png");
        fMultTOFMDC_FW_EtaCut->SaveAs("MultTOFMDC_FW_EtaCut.C","RECREATE");


TCanvas *fMultTOFMDC_FW_No = new TCanvas("fMultTOFMDC_FW_No");
        fMultTOFMDC_FW_No->cd();
        gPad-> SetLogz();
        MultTOFMDC_FW_No->GetXaxis()->SetTitle("TOF+MDC hits");
        MultTOFMDC_FW_No->GetYaxis()->SetTitle("FW charge, [GeV]");
        MultTOFMDC_FW_No->GetXaxis()->SetTitleSize(0.06);
MultTOFMDC_FW_No->GetYaxis()->SetTitleSize(0.06);
MultTOFMDC_FW_No->GetXaxis()->SetLabelSize(0.04);
MultTOFMDC_FW_No->GetYaxis()->SetLabelSize(0.04);
        MultTOFMDC_FW_No->Draw("COLZ");

        fMultTOFMDC_FW_No->Print("MultTOFMDC_FW_No.png");
        fMultTOFMDC_FW_No->SaveAs("MultTOFMDC_FW_No.C","RECREATE");


TCanvas *fMultMDC_FW = new TCanvas("fMultMDC_FW");
        fMultMDC_FW->cd();
        gPad-> SetLogz();
        MultMDC_FW->GetXaxis()->SetTitle("MDC tracks");
        MultMDC_FW->GetYaxis()->SetTitle("FW charge, [GeV]");
        MultMDC_FW->GetXaxis()->SetTitleSize(0.06);
MultMDC_FW->GetYaxis()->SetTitleSize(0.06);
MultMDC_FW->GetXaxis()->SetLabelSize(0.04);
MultMDC_FW->GetYaxis()->SetLabelSize(0.04);
        MultMDC_FW->Draw("COLZ");

        fMultMDC_FW->Print("MultMDC_FW.png");
        fMultMDC_FW->SaveAs("MultMDC_FW.C","RECREATE");

TCanvas *fMultMDC_FW_EtaCut = new TCanvas("fMultMDC_FW_EtaCut");
        fMultMDC_FW_EtaCut->cd();
        gPad-> SetLogz();
        MultMDC_FW_EtaCut->GetXaxis()->SetTitle("MDC tracks");
        MultMDC_FW_EtaCut->GetYaxis()->SetTitle("FW charge, [GeV]");
        MultMDC_FW_EtaCut->GetXaxis()->SetTitleSize(0.06);
MultMDC_FW_EtaCut->GetYaxis()->SetTitleSize(0.06);
MultMDC_FW_EtaCut->GetXaxis()->SetLabelSize(0.04);
MultMDC_FW_EtaCut->GetYaxis()->SetLabelSize(0.04);
        MultMDC_FW_EtaCut->Draw("COLZ");

        fMultMDC_FW_EtaCut->Print("MultMDC_FW_EtaCut.png");
        fMultMDC_FW_EtaCut->SaveAs("MultMDC_FW_EtaCut.C","RECREATE");

TCanvas *fMultMDC_FW_No = new TCanvas("fMultMDC_FW_No");
        fMultMDC_FW_No->cd();
        gPad-> SetLogz();
        MultMDC_FW_No->GetXaxis()->SetTitle("MDC tracks");
        MultMDC_FW_No->GetYaxis()->SetTitle("FW charge, [GeV]");
        MultMDC_FW_No->GetXaxis()->SetTitleSize(0.06);
MultMDC_FW_No->GetYaxis()->SetTitleSize(0.06);
MultMDC_FW_No->GetXaxis()->SetLabelSize(0.04);
MultMDC_FW_No->GetYaxis()->SetLabelSize(0.04);
        MultMDC_FW_No->Draw("COLZ");

        fMultMDC_FW_No->Print("MultMDC_FW_No.png");
        fMultMDC_FW_No->SaveAs("MultMDC_FW_No.C","RECREATE");


TCanvas *fMultTOFRPC_FW_No = new TCanvas("fMultTOFRPC_FW_No");
        fMultTOFRPC_FW_No->cd();
        gPad-> SetLogz();
        MultTOFRPC_FW_No->GetXaxis()->SetTitle("TOF+RPC hits");
        MultTOFRPC_FW_No->GetYaxis()->SetTitle("FW charge, [GeV]");
        MultTOFRPC_FW_No->GetXaxis()->SetTitleSize(0.06);
MultTOFRPC_FW_No->GetYaxis()->SetTitleSize(0.06);
MultTOFRPC_FW_No->GetXaxis()->SetLabelSize(0.04);
MultTOFRPC_FW_No->GetYaxis()->SetLabelSize(0.04);
        MultTOFRPC_FW_No->Draw("COLZ");

        fMultTOFRPC_FW_No->Print("MultTOFRPC_FW_No.png");
        fMultTOFRPC_FW_No->SaveAs("MultTOFRPC_FW_No.C","RECREATE");

TCanvas *fMultTOFRPC_FW_Cut = new TCanvas("fMultTOFRPC_FW_Cut");
        fMultTOFRPC_FW_Cut->cd();
        gPad-> SetLogz();
        MultTOFRPC_FW_Cut->GetXaxis()->SetTitle("TOF+RPC hits");
        MultTOFRPC_FW_Cut->GetYaxis()->SetTitle("FW charge, [GeV]");
        MultTOFRPC_FW_Cut->GetXaxis()->SetTitleSize(0.06);
MultTOFRPC_FW_Cut->GetYaxis()->SetTitleSize(0.06);
MultTOFRPC_FW_Cut->GetXaxis()->SetLabelSize(0.04);
MultTOFRPC_FW_Cut->GetYaxis()->SetLabelSize(0.04);
        MultTOFRPC_FW_Cut->Draw("COLZ");

        fMultTOFRPC_FW_Cut->Print("MultTOFRPC_FW_Cut.png");
        fMultTOFRPC_FW_Cut->SaveAs("MultTOFRPC_FW_Cut.C","RECREATE");




TCanvas *fMultTOF_FW_NoCuts = new TCanvas("fMultTOF_FW_NoCuts");
	fMultTOF_FW_NoCuts->cd();
	gPad-> SetLogz();
	MultTOF_FW_NoCuts->GetXaxis()->SetTitle("TOF M_{trk}");
	MultTOF_FW_NoCuts->GetYaxis()->SetTitle("FW charge, [GeV]");
	MultTOF_FW_NoCuts->GetXaxis()->SetTitleSize(0.06);
MultTOF_FW_NoCuts->GetYaxis()->SetTitleSize(0.06);
MultTOF_FW_NoCuts->GetXaxis()->SetLabelSize(0.04);
MultTOF_FW_NoCuts->GetYaxis()->SetLabelSize(0.04);

	MultTOF_FW_NoCuts->Draw("COLZ");

	fMultTOF_FW_NoCuts->Print("MultTOF_FW_Do.png");
	fMultTOF_FW_NoCuts->SaveAs("MultTOF_FW_Do.C","RECREATE");


TCanvas *fMultTOF_FW = new TCanvas("fMultTOF_FW");
        fMultTOF_FW->cd();
        gPad-> SetLogz();
        MultTOF_FW->GetXaxis()->SetTitle("TOF M_{trk}");
        MultTOF_FW->GetYaxis()->SetTitle("FW charge, [GeV]");
        MultTOF_FW->GetXaxis()->SetTitleSize(0.06);
MultTOF_FW->GetYaxis()->SetTitleSize(0.06);
MultTOF_FW->GetXaxis()->SetLabelSize(0.04);
MultTOF_FW->GetYaxis()->SetLabelSize(0.04);

        MultTOF_FW->Draw("COLZ");

        fMultTOF_FW->Print("MultTOF_FW.png");
        fMultTOF_FW->SaveAs("MultTOF_FW.C","RECREATE");

TCanvas *fhTracks_EtaCut = new TCanvas("fhTracks_EtaCut");
        fhTracks_EtaCut->cd();
        gPad-> SetLogz();
        hTracks_EtaCut->GetXaxis()->SetTitle("MDC M_{trk}");
        hTracks_EtaCut->GetYaxis()->SetTitle("Count");
        hTracks_EtaCut->GetXaxis()->SetTitleSize(0.06);
	hTracks_EtaCut->GetYaxis()->SetTitleSize(0.06);
	hTracks_EtaCut->GetXaxis()->SetLabelSize(0.04);
	hTracks_EtaCut->GetYaxis()->SetLabelSize(0.04);

        hTracks_EtaCut->Draw("COLZ");

        fhTracks_EtaCut->Print("hTracks_EtaCut.png");
        fhTracks_EtaCut->SaveAs("hTracks_EtaCut.C","RECREATE");
*/

/*
TCanvas *fMultTOF_VertexZ_NoCuts = new TCanvas("fMultTOF_VertexZ_NoCuts");
	fMultTOF_VertexZ_NoCuts->cd();
	gPad-> SetLogz();
	MultTOF_VertexZ_NoCuts->GetXaxis()->SetTitle("z_{vertex}, [cm]");
	MultTOF_VertexZ_NoCuts->GetYaxis()->SetTitle("TOF M_{trk}");
	MultTOF_VertexZ_NoCuts->Draw("COLZ");

	fMultTOF_VertexZ_NoCuts->Print("MultTOF_VertexZ_Do.png");
	fMultTOF_VertexZ_NoCuts->SaveAs("MultTOF_VertexZ_Do.C","RECREATE");

TCanvas *fMultTOF_VertexZ = new TCanvas("fMultTOF_VertexZ");
	fMultTOF_VertexZ->cd();
	gPad-> SetLogz();
	MultTOF_VertexZ->GetXaxis()->SetTitle("z_{vertex}, [cm]");
	MultTOF_VertexZ->GetYaxis()->SetTitle("TOF M_{trk}");
	MultTOF_VertexZ->Draw("COLZ");

	fMultTOF_VertexZ->Print("MultTOF_VertexZ_Posle.png");
	fMultTOF_VertexZ->SaveAs("MultTOF_VertexZ_Posle.C","RECREATE");

TCanvas *fSum_TOF_RPC = new TCanvas("fSum_TOF_RPC");
	fSum_TOF_RPC->cd();
	gPad-> SetLogy();
	Sum_TOF_RPC->SetLineColor(2);	
	Sum_TOF_RPC_NoCuts->SetLineColor(4);
	Sum_TOF_RPC->GetXaxis()->SetTitle("TOF+RPC M_{trk}");
	Sum_TOF_RPC->GetYaxis()->SetTitle("N_{events}");
	Sum_TOF_RPC->Draw();
	Sum_TOF_RPC_NoCuts->Draw("same");

	TLegend *leg3 = new TLegend(0.2, 0.15, 0.6, 0.4);
	leg3->SetFillColor(0);
	leg3->SetBorderSize(0);
	leg3->SetTextSize(0.03);
	leg3->SetTextFont(42);
	sprintf(tr, "%s", name1);
	leg3->AddEntry(Sum_TOF_RPC_NoCuts, tr, "l"); 
	sprintf(tr, "%s", name2);
	leg3->AddEntry(Sum_TOF_RPC, tr, "l");	
	leg3->Draw();

	fSum_TOF_RPC->Print("Sum_TOF_RPC_DoPosle.png");
	fSum_TOF_RPC->SaveAs("Sum_TOF_RPC_DoPosle.C","RECREATE");

	*/
/*

MultTOFMDC_FW_EtaCut->Fill(SumTofMdc,wallChargeTot);
        MultMDC_FW_EtaCut->Fill(nTracks,wallChargeTot);
        FWhits_MDC_EtaCut->Fill(nTracks,nWallHitsTot);
        MultMDC_TOFMDC_EtaCut->Fill(nTracks,SumTofMdc);
        hTracks_EtaCut->Fill(nTracks);

*/
TreeFile->cd();
	/*	MultTOF_NoCuts->Write();	
		FW_NoCuts->Write();
		vX_vY_NoCuts->Write();
		vZ_NoCuts->Write();
		 FW_VertexZ_NoCuts->Write();	
	//	MultTOF_FW_NoCuts->Write();
	//	Sum_TOF_RPC_NoCuts->Write();
	//	MultTOF_VertexZ_NoCuts->Write();
	//	MultTOF->Write();	
		FW->Write();
		vX_vY->Write();
		hvZ->Write();
		 FW_VertexZ->Write();	
//		MultTOF_FW->Write();
//		Sum_TOF_RPC->Write();
//		MultTOF_VertexZ->Write();
//		MultMDC_FW->Write();
		MultTOFRPC_FW->Write();
		 MultTOFRPC_FW_Cut->Write();
		 MultTOFRPC_FW_No->Write();
		hTracks_EtaCut->Write();
		hTracks->Write();
		MultTOFMDC_FW_EtaCut->Write();
		MultMDC_FW_EtaCut->Write();
		FWhits_MDC_EtaCut->Write();
		MultMDC_TOFMDC_EtaCut->Write();
		hTracks_EtaCut->Write();
*/

TreeFile->Close();
}
                        

