<?php 
	
	require_once '../../module/Connexion.php';
	require_once '../../module/models/categorie/Categorie.php';
	
	$id=(isset($_GET["id"]))?$_GET["id"]:"";
	
	if($id != ""){
		
		#valeur adapt� pour transformer le formulaire ajouForm en un Formulaire d'update
		$categorie= new Categorie();
		#r�cup�rer l'utilisateur dans la meme instruction
		$list= $categorie->findCategorie();
		
		while($data = $list->fetch()){
		
		$nom_categorie = $data["nom_categorie"];
		
		}
		$action = "updateAction";
		$bouton = "Modifier categorie";
	}else
	{
		#valeur par d�faut pour le formulaire ajoutForm
		$nom_categorie = "";
		
		
		$action = "ajoutAction";
		$bouton = "Ajouter categorie";
		
	}

?>
<div id="form">
  			<form name="ajoutCategorieForm" action="../../actions/categorie/<?php echo $action;?>.php" method="post">
	  			<table>
	  				<tr>
	  					<td colspan=2 id="bloc_erreur"></td>
	  				</tr>
	  				<tr>
	  					<td><label>Categorie</label></td>
	  					<td><input type="text" name="cat"  value=<?php echo $nom_categorie;?> ></td>
	  				</tr>
	  				
	  				<tr>
	  					<td colspan="2" align="center">
	  						
	  						<input class="btn" type="button" value="<?php echo $bouton;?>" onclick="validation(ajoutCategorieForm,'ajoutCategorieForm')"/>
	  						<input type="hidden" name="id"  value="<?php echo $id;?>"/></td>
	  					</td>
	  				</tr>
	  				<td>
	  				
	  			</table>
  			</form>
</div>