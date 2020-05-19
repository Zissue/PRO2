notes:
	// Campos del parámetro implícito //


	// Operaciones privadas //



	// Constructoras //



	// Modificadoras //



	// Entrada / Salida //



	// Consultoras //


/** @brief 
	@pre 
	@post 
*/


/** @brief Consulta el idioma a partir de un identificador (string)
    @pre El identificador (string del parámetro) tiene que existir.
    @post Devuelve el idioma consultado.
*/
	Idioma cons_idioma(const string& identificador) const;


/** @brief Si no existe ya un idioma con ese nombre (iden), se 
	añade un idioma nuevo a partir de dichos datos; en otro caso 
	si existe, se suman a la tabla del idioma existente las frecuencias 
	de la nueva tabla y, por lo tanto, se ha de obtener un nuevo 
	treecode y sus correspondientes códigos para el idioma
  	@pre <em>Cierto</em>
  	@post Si no existe el idioma, queda añadido en el p.i.; en otro caso,
  	se suma a la tabla de frecuencias existente y se vuelve a calcular su
  	<em>treecode</em>.
	*/
	void anadir_modificar_idioma(const string& iden, const map<char,int>& freqchart);
    
/** @brief Actualiza el conjunto de los idiomas
	@pre <em>Cierto</em>
	@post Añade o modifica un idioma segun si estaba anteriormente o no
*/
	void update_idioma(const string& nombreidioma);



	// string ifoundit(const map<string,string>& m, const string& tira) {
//     map<string,string>::const_iterator it = m.find(tira);
//     if (it != m.end()) return it->second;
//     return "";
// }

// void Idioma::update_lcode() {
//     int n = 0;
//     map<string,string>::const_iterator it;
//     for (it = invers.begin(); it != invers.end(); it++) {
//         if (it->first.size() > n) n = it->first.size();
//     }
//    	lcode = n;
// }

// pair<bool, int> Idioma::belong_and_decodetext(const string& text, string& decoded) {

//     string aux = "";
//     int pos = 0;
//     bool found = false;
// 	bool found2 = false;
// 	bool sucess = false;

//     for (int i = 0; i < text.size() and !found; i++) {
//         aux = text[i];
//         if (ifoundit(invers, aux) != "") {
//         	decoded += ifoundit(invers, aux);
//         	pos = i+1;
//         }
//         else {
// 			// cout << decoded << endl;
//             found2 = false;
//             for (int j = i+1; j < text.size() and j < lcode+i and !found2; j++) {
//             // for (int j = i+1; j < n+i+1 and !found2; j++) {
//                 // cout << aux << endl;
//                 aux += text[j];
//                 // cout << aux << "============" << endl;
//                 if (j == text.size()-1) {
//                     if (ifoundit(invers, aux) == "") {
//                         found = true;
//                         found2 = true;
//                         // decoded = "";
//                     }
//                     else {
//                 		found2 = true;
//                         sucess = true;
//                 		decoded += ifoundit(invers, aux);
//                 		pos = i+1;
//                     }
//                 }
//                 else {
//                     if (ifoundit(invers, aux) != "") {
//                         found2 = true;
//                         decoded += ifoundit(invers, aux);
//                         i += aux.size()-1;
//                         pos = i+1;
//                     }
//                 }
//             }
//         }
//     }

//     if (sucess or (!found and found2)) return make_pair(true, -5);
// 	return make_pair(false, pos-1);
// }


// /* brief Consultora para la tabla de frecuencias
// 	pre <em>Cierto</em>
// 	post Devuelve un conjunto de pares carácter y entero representado la tabla de frecuencias
// */
// 	Tabla cons_freqchart() const;

// /* brief Consultora para el treecode del p.i.
// 	pre <em>treecode</em> tiene que tener almenos un nodo
// 	post Devuelve el treecode del p.i.
// */
// 	Treecode cons_tree() const;

	/** @brief 
	@pre 
	@post 
*/
	// pair<bool, int> belong_and_decodetext(const string& text, string& decoded);


/** @brief <em>text</em> se decodificará con los códigos del idioma
	@pre <em>Cierto</em>
	@post Devuelve la codificación por el canal de salida estándar
*/
	// void cout_decodifica(const string& text);

	// /* @brief 
// 	@pre 
// 	@post 
// */
// 	bool cons_char(const string& c);


/** @brief Comprueba si a1 es menor que a2 con el siguiente criterio:
	si los enteros no son iguales, es más pequeña
	la raı́z con el entero más pequeño; en caso de empate, es más pequeña la raı́z con la string
	más pequeña en orden lexicográfico
	@pre <em>Cierto</em> 
	@post Devuelve true si <em>a1</em> es menor que <em>a2</em>
*/
	// static bool a1_menor_a2(const BinTree< pair<string,int> >& a1, const BinTree< pair<string,int> >& a2);




/* @brief Devuelve la tabla de frecuencias // Se utiliza esta función exclusivamente 
        para generar el treecode con su constructora
    @pre <em>Cierto</em>
    @post Devuelve el conjunto de la tabla de frecuencias
*/
    // map<string, int> cons_tabla() const;



/* @brief Comprueba si un <em>string</em> pertenece al idioma o no
    @pre <em>Cierto</em>
    @post Devuelve cierto si pertenece al idioma, falso en caso contrario
*/
    // bool pertenece(const string& word) const;



    // bool Idioma::pertenece(const string& word) const 
// {
//  cout << word << endl;
//  return true;
// }



	// bool Idioma::belong_codedchar(const string& code) const 
// {
//  for (map<string, string>::const_iterator it = codigos.begin(); it != codigos.end(); it++) {
//      if (it->second == code) return true;
//  }
//  return false;
// }


// map<string, int> Tabla::cons_tabla() const 
// {
//  return chart;
// }

	// void Treecode::update_codigos() 
// {
//  for (map<string, string>::iterator it = codigos.begin(); it != codigos.end(); it++) {
//      string s = "";
//      string letra = it->first;
//      it->second = codemaker(letra, treecode.cons_tree(), s);
//  }
// }

// void Treecode::setAbecedari(Tabla& t) 
// {
//  // map<string,int> aux = freqchart.cons_tabla();
//  string res = "";

//  for (map<string, int>::const_iterator it = freqchart.cons_it_begin(); it != freqchart.cons_it_end(); it++) {
//      pair<string, int> aux = freqchart.cons_it_esim(it);
//      pair<string, string> p(aux.first, res);
//      codigos.insert(p);
//  }
// }

	
// BinTree<pair<string, int> > Treecode::cons_tree() const 
// {
//  return arbol;
// }


// void Idioma::setAbecedari() 
// {
//     string res = "";

//     for (map<string, int>::iterator it = freqchart.cons_it_begin(); it != freqchart.cons_it_end(); it++) {
//         pair<string, int> aux = freqchart.cons_it_esim(it);
//         pair<string, string> p(aux.first, res);
//         codigos.insert(p);
//     }
// }

// void Idioma::update_codigos() 
// {
//     for (map<string, string>::iterator it = codigos.begin(); it != codigos.end(); it++) {
//         string letra = it->first;
//         it->second = treecode.code_char(letra);
//     }
// }


	/* @brief Establece en <em>códigos</em> del p.i. con los caracteres del idioma como 
        llaves (<em>first</em>) y con una <em>string</em> vacía (<em>second</em>)
    @pre <em>Cierto</em>
    @post <em>códigos</em> del p.i. con caracteres del idioma como <em>first</em> 
        y "" como <em>second</em> (codificación vacía)
*/
    // void setAbecedari();