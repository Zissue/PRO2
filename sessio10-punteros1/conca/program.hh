
/* Pre: c=C */
/* Post: el p.i. passa a ser la concatenació de C al paràmetre implícit, c és buida */

void concat(Cua &c) {
	if (this != &c) {

		if (c.longitud > 0) {

			if (longitud > 0) {
				longitud += c.longitud;
				ultim_node->seguent = c.primer_node;
				ultim_node = c.ultim_node;
			}
			else {
				longitud = c.longitud;
				primer_node = c.primer_node;
				ultim_node = c.ultim_node;
			}
			c.longitud = 0;
			c.primer_node = nullptr;
			c.ultim_node = nullptr;
		}
	}
}