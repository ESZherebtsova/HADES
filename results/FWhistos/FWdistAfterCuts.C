{
//=========Macro generated from canvas: c004/
//=========  (Fri Nov 24 20:06:36 2017) by ROOT version5.34/34
   TCanvas *c004 = new TCanvas("c004", "",65,52,700,527);
   gStyle->SetOptStat(0);
   c004->Range(-1306.25,3.888245,11256.25,7.880673);
   c004->SetFillColor(0);
   c004->SetBorderMode(0);
   c004->SetBorderSize(2);
   c004->SetLogy();
   c004->SetFrameBorderMode(0);
   c004->SetFrameBorderMode(0);
   
   TH1F *hFWdist = new TH1F("hFWdist","",70000,-35000,35000);
   hFWdist->SetBinContent(35001,38772);
   hFWdist->SetBinContent(41855,1.59912e+07);
   hFWdist->SetBinContent(41856,1.443813e+07);
   hFWdist->SetBinContent(41857,9352682);
   hFWdist->SetBinContent(41858,9009902);
   hFWdist->SetBinContent(41859,8062540);
   hFWdist->SetBinContent(41860,3429278);
   hFWdist->SetBinContent(41861,8971015);
   hFWdist->SetBinContent(41862,7421917);
   hFWdist->SetBinContent(41864,9216845);
   hFWdist->SetBinContent(41865,7341228);
   hFWdist->SetBinContent(41866,2554545);
   hFWdist->SetBinContent(41867,4893871);
   hFWdist->SetBinContent(41870,4415447);
   hFWdist->SetBinContent(41872,6293839);
   hFWdist->SetBinContent(41874,1.410415e+07);
   hFWdist->SetBinContent(41879,1.087422e+07);
   hFWdist->SetBinContent(41885,4809752);
   hFWdist->SetBinContent(41887,9195032);
   hFWdist->SetBinContent(41888,2168486);
   hFWdist->SetBinContent(41889,2195696);
   hFWdist->SetBinContent(41892,7480438);
   hFWdist->SetBinContent(41901,4493008);
   hFWdist->SetBinContent(41902,3389873);
   hFWdist->SetBinContent(41903,5215594);
   hFWdist->SetBinContent(41909,4862603);
   hFWdist->SetBinContent(41914,1242263);
   hFWdist->SetBinContent(41915,1204342);
   hFWdist->SetBinContent(41918,3800321);
   hFWdist->SetBinContent(70001,2651);
   hFWdist->SetEntries(1.864696e+08);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hFWdist->SetLineColor(ci);
   hFWdist->GetXaxis()->SetRange(34951,45000);
   hFWdist->GetXaxis()->SetLabelFont(42);
   hFWdist->GetXaxis()->SetLabelSize(0.035);
   hFWdist->GetXaxis()->SetTitleSize(0.035);
   hFWdist->GetXaxis()->SetTitleFont(42);
   hFWdist->GetYaxis()->SetLabelFont(42);
   hFWdist->GetYaxis()->SetLabelSize(0.035);
   hFWdist->GetYaxis()->SetTitleSize(0.035);
   hFWdist->GetYaxis()->SetTitleFont(42);
   hFWdist->GetZaxis()->SetLabelFont(42);
   hFWdist->GetZaxis()->SetLabelSize(0.035);
   hFWdist->GetZaxis()->SetTitleSize(0.035);
   hFWdist->GetZaxis()->SetTitleFont(42);
   hFWdist->Draw("");
   TLatex *   tex = new TLatex(6972.761,276.8442,"");
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(-820.3081,8528945,"Counts");
   tex->SetTextFont(42);
   tex->SetTextAngle(89.16969);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(6126.862,10000,"Distance to FW module");
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
   c004->Modified();
   c004->cd();
   c004->SetSelected(c004);
   c004->ToggleToolBar();
}
