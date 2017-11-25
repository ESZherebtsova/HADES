{
//=========Macro generated from canvas: fEtaPt/
//=========  (Thu Nov 16 23:58:35 2017) by ROOT version5.34/14
   TCanvas *fEtaPt = new TCanvas("fEtaPt", "",65,52,700,500);
   fEtaPt->Range(-0.2,-275,1.8,2475);
   fEtaPt->SetFillColor(0);
   fEtaPt->SetBorderMode(0);
   fEtaPt->SetBorderSize(2);
   fEtaPt->SetLogz();
   fEtaPt->SetFrameBorderMode(0);
   fEtaPt->SetFrameBorderMode(0);
   
   TH2F *hEta_Pt = new TH2F("hEta_Pt","",160,0,1.6,2200,0,2200);
   hEta_Pt->SetBinContent(323,1.677722e+07);
   hEta_Pt->SetEntries(3.730974e+07);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.695,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("hEta_Pt");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries =   3.730974e+07");
   text = ptstats->AddText("Mean x =      0");
   text = ptstats->AddText("Mean y =      0");
   text = ptstats->AddText("RMS x =      0");
   text = ptstats->AddText("RMS y =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   hEta_Pt->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(hEta_Pt);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#000099");
   hEta_Pt->SetLineColor(ci);
   hEta_Pt->GetXaxis()->SetTitle("p_{T}, [Gev/c]");
   hEta_Pt->GetXaxis()->SetLabelFont(42);
   hEta_Pt->GetXaxis()->SetTitleSize(0.06);
   hEta_Pt->GetXaxis()->SetTitleFont(42);
   hEta_Pt->GetYaxis()->SetTitle("#eta");
   hEta_Pt->GetYaxis()->SetLabelFont(42);
   hEta_Pt->GetYaxis()->SetTitleSize(0.06);
   hEta_Pt->GetYaxis()->SetTitleFont(42);
   hEta_Pt->GetZaxis()->SetLabelFont(42);
   hEta_Pt->GetZaxis()->SetLabelSize(0.035);
   hEta_Pt->GetZaxis()->SetTitleSize(0.035);
   hEta_Pt->GetZaxis()->SetTitleFont(42);
   hEta_Pt->Draw("COLZ");
   fEtaPt->Modified();
   fEtaPt->cd();
   fEtaPt->SetSelected(fEtaPt);
}
