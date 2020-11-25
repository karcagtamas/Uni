program Project1;

uses
  Vcl.Forms,
  Proj2 in 'Proj2.pas' {Form1};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TMyForm, MyForm);
  Application.Run;
end.
