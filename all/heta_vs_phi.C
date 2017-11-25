{
//=========Macro generated from canvas: fEta_Phi/
//=========  (Wed Nov 22 13:59:16 2017) by ROOT version5.34/14
   TCanvas *fEta_Phi = new TCanvas("fEta_Phi", "",65,52,700,500);
   fEta_Phi->Range(-0.2,-0.7850001,1.8,7.065);
   fEta_Phi->SetFillColor(0);
   fEta_Phi->SetBorderMode(0);
   fEta_Phi->SetBorderSize(2);
   fEta_Phi->SetLogz();
   fEta_Phi->SetFrameBorderMode(0);
   fEta_Phi->SetFrameBorderMode(0);
   
   TH2F *heta_vs_phi = new TH2F("heta_vs_phi","",160,0,1.6,628,0,6.28);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.695,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("heta_vs_phi");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 0      ");
   text = ptstats->AddText("Mean x =      0");
   text = ptstats->AddText("Mean y =      0");
   text = ptstats->AddText("RMS x =      0");
   text = ptstats->AddText("RMS y =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   heta_vs_phi->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(heta_vs_phi);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#000099");
   heta_vs_phi->SetLineColor(ci);
   heta_vs_phi->GetXaxis()->SetTitle("#eta");
   heta_vs_phi->GetXaxis()->SetLabelFont(42);
   heta_vs_phi->GetXaxis()->SetLabelSize(0.035);
   heta_vs_phi->GetXaxis()->SetTitleSize(0.035);
   heta_vs_phi->GetXaxis()->SetTitleFont(42);
   heta_vs_phi->GetYaxis()->SetTitle("#phi, [rad]");
   heta_vs_phi->GetYaxis()->SetLabelFont(42);
   heta_vs_phi->GetYaxis()->SetLabelSize(0.035);
   heta_vs_phi->GetYaxis()->SetTitleSize(0.035);
   heta_vs_phi->GetYaxis()->SetTitleFont(42);
   heta_vs_phi->GetZaxis()->SetLabelFont(42);
   heta_vs_phi->GetZaxis()->SetLabelSize(0.035);
   heta_vs_phi->GetZaxis()->SetTitleSize(0.035);
   heta_vs_phi->GetZaxis()->SetTitleFont(42);
   heta_vs_phi->Draw("COLZ");
   fEta_Phi->Modified();
   fEta_Phi->cd();
   fEta_Phi->SetSelected(fEta_Phi);
}
