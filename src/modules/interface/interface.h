#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "livro.h"
#include "usuario.h"
#include "emprestimo.h"

void MSG_MENU(); // MENU PRINCIPAL

void MSG_SUBMENU(int numero_modulo); // SUBMENU MÓDULOS

void SubMenuModulo1(TModuloLivro *modulo1, TLivro livro);

void SubMenuModulo2(TModuloUsuario *modulo2, TUsuario usuario);

void SubMenuModulo3(TModuloEmprestimo *modulo3, TEmprestimo emprestimo);

#endif // INTERFACE_H_INCLUDED