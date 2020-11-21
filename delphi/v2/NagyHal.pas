unit NagyHal;

interface

uses
  Alakzatok, Graphics;

type TNagyHal=class(TTeliKor)
  private
    private PSpeed: Integer;
  public
    constructor Create(Cx: Integer; Cy: Integer; Size: Integer; Color: TColor; SpeedIn: Integer);
    // procedure Kirak(AktSzin:TColor; Hova:TCanvas); override;
    property Speed: Integer read PSpeed write PSpeed;
end;

implementation

constructor TNagyHal.Create(Cx: Integer; Cy: Integer; Size: Integer; Color: TColor; SpeedIn: Integer);
begin
     inherited Create(Cx, Cy, Size, Color);
     Speed := SpeedIn;
end;

end.
