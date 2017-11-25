{
//=========Macro generated from canvas: fMultTOF_FW_NoCuts/
//=========  (Fri Nov 17 00:00:15 2017) by ROOT version5.34/14
   TCanvas *fMultTOF_FW_NoCuts = new TCanvas("fMultTOF_FW_NoCuts", "",65,52,700,500);
   fMultTOF_FW_NoCuts->Range(-15,-2500,135,22500);
   fMultTOF_FW_NoCuts->SetFillColor(0);
   fMultTOF_FW_NoCuts->SetBorderMode(0);
   fMultTOF_FW_NoCuts->SetBorderSize(2);
   fMultTOF_FW_NoCuts->SetLogz();
   fMultTOF_FW_NoCuts->SetFrameBorderMode(0);
   fMultTOF_FW_NoCuts->SetFrameBorderMode(0);
   
   TH2F *MultTOF_FW_NoCuts = new TH2F("MultTOF_FW_NoCuts","",120,0,120,200,0,20000);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.695,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("MultTOF_FW_NoCuts");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 0      ");
   text = ptstats->AddText("Mean x =      0");
   text = ptstats->AddText("Mean y =      0");
   text = ptstats->AddText("RMS x =      0");
   text = ptstats->AddText("RMS y =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   MultTOF_FW_NoCuts->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(MultTOF_FW_NoCuts);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#000099");
   MultTOF_FW_NoCuts->SetLineColor(ci);
   MultTOF_FW_NoCuts->GetXaxis()->SetTitle("TOF M_{trk}");
   MultTOF_FW_NoCuts->GetXaxis()->SetLabelFont(42);
   MultTOF_FW_NoCuts->GetXaxis()->SetTitleSize(0.06);
   MultTOF_FW_NoCuts->GetXaxis()->SetTitleFont(42);
   MultTOF_FW_NoCuts->GetYaxis()->SetTitle("FW charge, [GeV]");
   MultTOF_FW_NoCuts->GetYaxis()->SetLabelFont(42);
   MultTOF_FW_NoCuts->GetYaxis()->SetTitleSize(0.06);
   MultTOF_FW_NoCuts->GetYaxis()->SetTitleFont(42);
   MultTOF_FW_NoCuts->GetZaxis()->SetLabelFont(42);
   MultTOF_FW_NoCuts->GetZaxis()->SetLabelSize(0.035);
   MultTOF_FW_NoCuts->GetZaxis()->SetTitleSize(0.035);
   MultTOF_FW_NoCuts->GetZaxis()->SetTitleFont(42);
   MultTOF_FW_NoCuts->Draw("COLZ");
   fMultTOF_FW_NoCuts->Modified();
   fMultTOF_FW_NoCuts->cd();
   fMultTOF_FW_NoCuts->SetSelected(fMultTOF_FW_NoCuts);
}
