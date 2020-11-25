unit Unit2;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls;

type

  { TForm2 }

  TForm2 = class(TForm)
    Label1: TLabel;
  private

  public
    constructor Create(AOwner: TComponent; DisplayText: String);

  end;

var
  Form2: TForm2;

implementation

constructor TForm2.Create(AOwner: TComponent; DisplayText: String);
begin
     Label1.Caption := DisplayText;
end;

{$R *.lfm}

end.

