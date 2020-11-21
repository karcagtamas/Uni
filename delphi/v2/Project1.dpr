program Project1;

uses
  Vcl.Forms,
  Unit2 in 'Unit2.pas' {Form2},
  Alakzatok in '..\..\..\..\..\Egyetem\felev_2\komp\12\Alakzatok.pas',
  NagyHal in 'NagyHal.pas';

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TForm2, Form2);
  Application.Run;
end.
