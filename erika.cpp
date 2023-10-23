#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Data {
    private:
    int dia;
    int mes;
    int ano;

    public:
    //Construtor
     Data(int _dia, int _mes, int _ano) 
        : dia(_dia), mes(_mes), ano(_ano) {}

    //Setters
    void setDia(int _dia){
        this->dia = _dia;
    }

    void setMes(int _mes){
        this->mes = _mes;
    }

    void setAno(int _ano){
        this->ano = _ano;
    }

    //Getters
    int getDia(){
        return this->dia;
    }

    int getMes(){
        return this->mes;
    }

    int getAno(){
        return this->ano;
    }

   /*  Data getDtNascimento(){
        return this->dtNascimento;
    } */

};

class Paciente{
    string cpf;
    Data dtNascimento; //ideal tipo Data ou struct tm
    public:
        string nome;

          Paciente(string _nomePaciente, string _cpf,  Data _dtNascimento)
        : cpf(_cpf), nome(_nomePaciente), dtNascimento(_dtNascimento) {}

        string getCpf(){
            return this->cpf;
        }

        void setCpf(string _cpf){
            /* validar quantidade de caracteres 11 ou 14
            */
           this->cpf = _cpf;
        }

        void setdtNascimento(Data _dtNascimento){
            this->dtNascimento = _dtNascimento;
        }


       /*  string getDtNascimento(){
            return this->dtNascimento;
        } */

        /* void setDtNascimento(Data _dtNascimento){
            
           this->dtNascimento = _dtNascimento;
        }  */

        Data getDtNascimento(){
            return this->dtNascimento;
        }
};


int localizaCpf(vector<Paciente*> pacientes, string cpf){
    int i=0;
    for(auto el : pacientes){
        if(el->getCpf() == cpf){
            return i;
        }
        i++;
    }

    return -1;
}


class Medico{
    string crm;
    string especialidade; //ideal tipo Data ou struct tm
    public:
        string nome;

        Medico(string _nome,string _crm,string _especialidade){
            this->nome = _nome;
            this->crm = _crm;
            this->especialidade = _especialidade;
            //Não necessariamente precisa passar no set dentro do construtor
            /* this->setCrm(_crm);
            this->setEspecialidade(_especialidade); */
        }

        string getCrm(){
            return this->crm;
        }

        //trocar o metodo para troca setcrm
        void setCrm(string _crm){
            /* validar quantidade de caracteres 11 ou 14
            */
           this->crm = _crm;
        }


        string getEspecialidade(){
            return this->especialidade;
        }

        void setEspecialidade(string _especialidade){
            /* validar quantidade de caracteres e formato
            */
           this->especialidade = _especialidade;
        } 
};


int localizaCrm(vector<Medico*> medicos, string crm){
    int i=0;
    for(auto el : medicos){
        if(el->getCrm() == crm){
            return i;
        }
        i++;
    }

    return -1;
}

int main(){

    int opcaoPrincipal;
    int opcao;
    vector<Paciente*> listaPacientes;
    vector<Medico*> listaMedicos;

    do{
            cout << "Informe a opcao (0-2): " << endl;
            cout << "1. Pacientes" << endl;
            cout << "2. Medicos" << endl;
            cin >> opcaoPrincipal;

        if(opcaoPrincipal == 1){
             do{
                cout << "---- PACIENTES ------" << endl;
                cout << "Informe a opcao (0-5): " << endl;
                cout << "1. Incluir" << endl;
                cout << "2. Excluir (por CPF)" << endl;
                cout << "3. Alterar (por CPF)" << endl;
                cout << "4. Listar" << endl;
                cout << "5. Localizar (por CPF)" << endl;
                cout << "0. Sair" << endl;
                cin >> opcao;
        
        string auxNome, auxCpf, auxDtNasc;
        int dia, mes, ano;
        if(opcao==1){
            cout << "Informe o nome: ";
            getline(cin >> ws, auxNome);

            cout << "Informe o CPF: ";
            getline(cin >> ws, auxCpf);

            /* cout << "Informe a Data de Nascimento: ";
            getline(cin >> ws, auxDtNasc); */
            cout << "Informe o dia do seu nascimento: " << endl;
            cin >> dia;
            cout << "Informe o mes do seu nascimento: " << endl;
            cin >> mes;
            cout << "Informe o ano do seu nascimento: " << endl;
            cin >> ano;

            if(auxCpf.length() != 11){
                cout << "CPF invalido!" << endl;
                break;
            }

            int posicao = localizaCpf(listaPacientes,auxCpf);

            if(posicao  < 0){
                Data data (dia, mes, ano);
                Paciente *paciente = new Paciente(auxNome, auxCpf, data);
                listaPacientes.push_back(paciente);
            }
            else{
                cout << "Paciente ja inserido" << endl;
            }

            
        }
        else if(opcao==2){
            cout << "Informe o CPF do paciente que deseja excluir: ";
            getline(cin >> ws, auxCpf);

            int posicao = localizaCpf(listaPacientes,auxCpf);

            if(posicao  < 0)
                cout << "Paciente não encontrado" << endl;
            else{
                listaPacientes.erase(listaPacientes.begin() + posicao);
            }
        }
        else if(opcao==3){
            cout << "Informe o CPF do paciente que deseja alterar: ";
            getline(cin >> ws, auxCpf);

            int posicao = localizaCpf(listaPacientes,auxCpf);

            if(posicao  < 0)
                cout << "Paciente não encontrado" << endl;
            else{
                int escolha;
                string novoNome;
                string novaData;
                cout << "Nome: " << listaPacientes[posicao]->nome << endl;
                cout << "CPF: " << listaPacientes[posicao]->getCpf() << endl;
                cout << "Data de Nascimento: " << listaPacientes[posicao]->getDtNascimento().getDia();
                cout << " / " << listaPacientes[posicao]->getDtNascimento().getMes();
                cout << " / " << listaPacientes[posicao]->getDtNascimento().getAno() << endl;

                cout << "Deseja alterar o nome? 1-Sim / 2 - Nao" << endl;
                cin>> escolha;

                if(escolha == 1){
                    cout << "Informe o nome do paciente: " << endl;
                    getline(cin >> ws, novoNome);
                    listaPacientes[posicao]->nome = novoNome;
                }else{  }

                cout << "Deseja alterar a data? 1-Sim / 2 - Nao" << endl;
                cin>> escolha;

                if(escolha == 1){
                    cout << "Informe o dia do seu nascimento: " << endl;
                    cin >> dia;
                    cout << "Informe o mes do seu nascimento: " << endl;
                    cin >> mes;
                    cout << "Informe o ano do seu nascimento: " << endl;
                    cin >> ano;

                    Data data (dia, mes, ano);
                    listaPacientes[posicao]->setdtNascimento(data);
                }else{  }

            }

        }else if(opcao==4){
            for(auto el : listaPacientes){
                cout << el->nome << endl;
                cout << el->getCpf() << endl;
                cout << "Data de Nascimento: " << el->getDtNascimento().getDia();
                cout << " / " << el->getDtNascimento().getMes();
                cout << " / " << el->getDtNascimento().getAno() << endl;
                cout << endl;
            }
        }else if(opcao==5){
            cout << "Informe o CPF do paciente que deseja alterar: ";
            getline(cin >> ws, auxCpf); 

            int posicao = localizaCpf(listaPacientes,auxCpf);

            if(posicao < 0)
                cout << "Paciente não encontrado" << endl;
            else{
                cout << listaPacientes.at(posicao)->nome << endl;
            }
        }else if(opcao==0){
            // sair desse menu
        } else{
            cout << "Opção inválida" << endl;
        }
         }while(opcao != 0);


        }else if(opcaoPrincipal == 2){        

        
       
            do{
                cout << "---- MEDICOS ------" << endl;
                cout << "Informe a opcao (0-5): " << endl;
                cout << "1. Incluir" << endl;
                cout << "2. Excluir (por CRM)" << endl;
                cout << "3. Alterar (por CRM)" << endl;
                cout << "4. Listar" << endl;
                cout << "5. Localizar (por CRM)" << endl;
                cout << "0. Sair" << endl;
                cin >> opcao;
        //Criou as varias fora do espoco da opcao 1
       // string auxNome, auxCrm, auxespecialidade;
        if(opcao==1){
                //Criou a auxespecialidade com "e" minusculo
                string auxNome, auxCrm, auxEspecialidade;
                cout << "Informe o nome do médico: ";
                getline(cin >> ws, auxNome);

                cout << "Informe o CRM: ";
                getline(cin >> ws, auxCrm);

                cout << "Informe a especialidade: ";
                getline(cin >> ws, auxEspecialidade);
                //Esqueceu de trocar o nome do metodo para localizarCrm
                int posicao = localizaCrm(listaMedicos,auxCrm);

                if(posicao  < 0){
                    Medico *medico = new Medico(auxNome, auxCrm, auxEspecialidade);
                    listaMedicos.push_back(medico);
                }
                else{
                    cout << "Medico ja inserido" << endl;
                }

            }
            else if(opcao==2){
                //esqueceu de criar a variavel auxCrm
                string auxCrm;
                cout << "Informe o CRM do medico que deseja excluir: ";
                getline(cin >> ws, auxCrm);

                int posicao = localizaCrm(listaMedicos,auxCrm);

                if(posicao  < 0)
                    cout << "Medico não encontrado" << endl;
                else{
                    listaMedicos.erase(listaMedicos.begin() + posicao);
                }
            }
            else if(opcao==3){
                //esqueceu de criar a variavel auxCrm
                string auxCrm;
                cout << "Informe o CRM do medico que deseja alterar: ";
                getline(cin >> ws, auxCrm);

                int posicao = localizaCrm(listaMedicos,auxCrm);

                if(posicao  < 0)
                    cout << "Medico não encontrado" << endl;
                else{
                    int escolha;
                    // esqueceu de criar a variavel nova funcionalidade
                   // string novoNome;
                    //string novaData;
                    string novoNome, novaEspecialidade;
                    cout << "Nome: " << listaMedicos[posicao]->nome << endl;
                    cout << "CRM: " << listaMedicos[posicao]->getCrm() << endl;
                    cout << "Especialidade: " << listaMedicos[posicao]->getEspecialidade() << endl;

                    cout << "Deseja alterar o nome? 1-Sim / 2 - Nao" << endl;
                    cin>> escolha;

                    if(escolha == 1){
                        cout << "Informe o nome do medico: " << endl;
                        getline(cin >> ws, novoNome);
                        listaMedicos[posicao]->nome = novoNome;
                    }else{  }

                    cout << "Deseja alterar a especialidade? 1-Sim / 2 - Nao" << endl;
                    cin>> escolha;

                    if(escolha == 1){
                        cout << "Informe a especialidade: " << endl;
                        getline(cin >> ws, novaEspecialidade);
                        //nesse vc passou data no set especilidade, tem que passa a nova funcionalidade
                        //listaMedicos[posicao]->setEspecialidade(novaData);
                        listaMedicos[posicao]->setEspecialidade(novaEspecialidade);
                    }else{  }

                }

            }else if(opcao==4){
                for(auto el : listaMedicos){
                    cout << el->nome << endl;
                    cout << el->getCrm() << endl;
                    cout << el->getEspecialidade() << endl;
                    cout << endl;
                }
            }else if(opcao==5){
                //esqueceu de criar a variavel auxCrm
                string auxCrm;
                cout << "Informe o CRM do medico que deseja alterar: ";
                getline(cin >> ws, auxCrm); 

                int posicao = localizaCrm(listaMedicos,auxCrm);

                if(posicao < 0)
                    cout << "Medico não encontrado" << endl;
                else{
                    cout << listaMedicos.at(posicao)->nome << endl;
                }
            }else if(opcao==0){
                // sair desse menu
            } else{
                cout << "Opção inválida" << endl;
            }
         }while(opcao != 0);

        }



    }while(opcaoPrincipal != 0);


return 0;
}