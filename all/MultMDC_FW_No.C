{
//=========Macro generated from canvas: fMultMDC_FW_No/
//=========  (Thu Nov 16 23:59:57 2017) by ROOT version5.34/14
   TCanvas *fMultMDC_FW_No = new TCanvas("fMultMDC_FW_No", "",65,52,700,500);
   fMultMDC_FW_No->Range(-15,-1875,135,16875);
   fMultMDC_FW_No->SetFillColor(0);
   fMultMDC_FW_No->SetBorderMode(0);
   fMultMDC_FW_No->SetBorderSize(2);
   fMultMDC_FW_No->SetLogz();
   fMultMDC_FW_No->SetFrameBorderMode(0);
   fMultMDC_FW_No->SetFrameBorderMode(0);
   
   TH2F *MultMDC_FW_No = new TH2F("MultMDC_FW_No","",120,0,120,150,0,15000);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.695,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("MultMDC_FW_No");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 0      ");
   text = ptstats->AddText("Mean x =      0");
   text = ptstats->AddText("Mean y =      0");
   text = ptstats->AddText("RMS x =      0");
   text = ptstats->AddText("RMS y =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   MultMDC_FW_No->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(MultMDC_FW_No);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#000099");
   MultMDC_FW_No->SetLineColor(ci);
   MultMDC_FW_No->GetXaxis()->SetTitle("MDC tracks");
   MultMDC_FW_No->GetXaxis()->SetLabelFont(42);
   MultMDC_FW_No->GetXaxis()->SetTitleSize(0.06);
   MultMDC_FW_No->GetXaxis()->SetTitleFont(42);
   MultMDC_FW_No->GetYaxis()->SetTitle("FW charge, [GeV]");
   MultMDC_FW_No->GetYaxis()->SetLabelFont(42);
   MultMDC_FW_No->GetYaxis()->SetTitleSize(0.06);
   MultMDC_FW_No->GetYaxis()->SetTitleFont(42);
   MultMDC_FW_No->GetZaxis()->SetLabelFont(42);
   MultMDC_FW_No->GetZaxis()->SetLabelSize(0.035);
   MultMDC_FW_No->GetZaxis()->SetTitleSize(0.035);
   MultMDC_FW_No->GetZaxis()->SetTitleFont(42);
   MultMDC_FW_No->Draw("COLZ");
   fMultMDC_FW_No->Modified();
   fMultMDC_FW_No->cd();
   fMultMDC_FW_No->SetSelected(fMultMDC_FW_No);
}
